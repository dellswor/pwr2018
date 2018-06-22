#include <assert.h>
#include "pwr_rapldev.h"
#include "pwr_dev.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

#include <msr_core.h>
#include <msr_rapl.h>

typedef struct {
	int fd;

	int cpu_model;
} pwr_msrdev_t;
#define MAX_CPU         512	
#define MAX_NUM_PKGS    8 
typedef struct {
	int numPkgs;
	pwr_msrdev_t* pkgs[MAX_NUM_PKGS];    
} private_data_t;

typedef struct {
	pwr_msrdev_t *dev;
} pwr_msrfd_t;
#define PWR_MSRFD(X) ((pwr_msrfd_t *)(X))

static plugin_devops_t devops = {
	.open         = pwr_msrdev_open,
	.close        = pwr_msrdev_close,
	.read         = pwr_msrdev_read,
	.write        = pwr_msrdev_write,
	.readv        = pwr_msrdev_readv,
	.writev       = pwr_msrdev_writev,
	.time         = pwr_msrdev_time,
	.clear        = pwr_msrdev_clear,
#if 0
	.stat_get     = pwr_dev_stat_get,
	.stat_start   = pwr_dev_stat_start,
	.stat_stop    = pwr_dev_stat_stop,
	.stat_clear   = pwr_dev_stat_clear,
#endif
	.private_data = 0x0
};

static struct rapl_data *rdat;
static uint64_t *rflags;
plugin_devops_t *pwr_msrdev_init( const char *initstr )
{
	int i;

	plugin_devops_t *dev = malloc( sizeof(plugin_devops_t) );
	private_data_t* priv = dev->private_data = malloc( sizeof(private_data_t) );

	priv->numPkgs = 0;

	init_msr();
	rapl_init(&rdat, &rflags);

	DBGP("num packages %d\n", priv->numPkgs );
	assert( priv->numPkgs > 0 );

	*dev = devops;
	dev->private_data = priv;
	return dev;
}

int pwr_msrdev_final( plugin_devops_t *dev )
{
    DBGP( "Info: PWR RAPL device close\n" );

    private_data_t* priv = dev->private_data;  
    int i;
    for ( i = 0; i < priv->numPkgs; i++) {

	free( priv->pkgs[i] );	
    } 
    free( dev->private_data );
    free( dev );

    return 0;
}
pwr_fd_t pwr_msrdev_open( plugin_devops_t *dev, const char *openstr )
{
	private_data_t *info = (private_data_t*) dev->private_data;
	pwr_msrfd_t *fd = malloc( sizeof(pwr_msrfd_t) );

	int   rc;
	int   global_index;
	PWR_ObjType type;

	sscanf( openstr, "%d %d", &type, &global_index );
	DBGP("type=%d global_index=%d\n",type,global_index);


	assert( global_index < info->numPkgs );

	fd->dev = info->pkgs[global_index ];

	return fd;
}
int pwr_msrdev_close( pwr_fd_t fd )
{
	PWR_MSRFD(fd)->dev = 0x0;
	free( fd );

	return 0;
}

int pwr_msrdev_read( pwr_fd_t fd, PWR_AttrName attr, void *value, unsigned int len, PWR_Time *timestamp )
{
	int i;
	double energy = 0.0;
	double time = 0.0;
	int policy = 0;
#ifndef USE_SYSTIME
	struct timeval tv;
#endif

	DBGP( "Info: PWR RAPL device read\n" );

	if( len != sizeof(double) ) {
		fprintf( stderr, "Error: value field size of %u incorrect, should be %ld\n", len, sizeof(double) );
		return -1;
	}
	poll_rapl_data();
	energy = rdat->pkg_delta_joules[0];

	switch( attr ) {
		case PWR_ATTR_ENERGY:
			*((double *)value) = energy;
			break;
		default:
			fprintf( stderr, "Warning: unknown PWR reading attr requested\n" );
			break;
	}


#ifndef USE_SYSTIME
	gettimeofday( &tv, NULL );
	*timestamp = tv.tv_sec*1000000000ULL + tv.tv_usec*1000;
#else
	*timestamp = (unsigned int)time*1000000000ULL + 
		(time-(unsigned int)time)*1000000000ULL;
#endif

	return 0;
}
int pwr_msrdev_write( pwr_fd_t fd, PWR_AttrName attr, void *value, unsigned int len )
{
	return 0;
}

int pwr_msrdev_readv( pwr_fd_t fd, unsigned int arraysize,
		const PWR_AttrName attrs[], void *values, PWR_Time timestamp[], int status[] )
{
	unsigned int i;

	for( i = 0; i < arraysize; i++ )
		status[i] = pwr_msrdev_read( fd, attrs[i], (double *)values+i, sizeof(double), timestamp+i );

	return 0;
}

int pwr_msrdev_writev( pwr_fd_t fd, unsigned int arraysize,
		const PWR_AttrName attrs[], void *values, int status[] )
{
	unsigned int i;

	for( i = 0; i < arraysize; i++ )
		status[i] = pwr_msrdev_write( fd, attrs[i], (double *)values+i, sizeof(double) );

	return 0;
}

int pwr_msrdev_time( pwr_fd_t fd, PWR_Time *timestamp )
{
	double value;

	DBGP( "Info: PWR MSR device time\n" );

	return pwr_msrdev_read( fd, PWR_ATTR_POWER, &value, sizeof(double), timestamp );
}

int pwr_msrdev_clear( pwr_fd_t fd )
{
	return 0;
}

static plugin_dev_t dev = {
	.init   = pwr_msrdev_init,
	.final  = pwr_msrdev_final,
};
