#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <mpi.h>
#include <dlfcn.h>
#include <pthread.h>
#include <assert.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


static int monitoring = 1;
static int writing = 1;

#include "pwr.h"
#include "time.c"
#include "powerprofiler.c"

int main()
{
	return 0;
}

pthread_t powThread;
int profrank;
int logfd;
FILE *logfile=NULL;
#include "mpi_wrappers.c"


int init()
{
	MPI_Comm_rank(MPI_COMM_WORLD, &profrank);
	long hostid = gethostid();
	char fname[100];
	sprintf(fname, "%lu.dat", hostid);

	logfd=open(fname,O_WRONLY|O_CREAT|O_NDELAY, S_IRUSR|S_IWUSR);
	if(logfd<0)
	{
		printf("failed to get file descriptor: %i, errno: %i\n",logfd,errno);
		return 1;	
	}
	logfile = fdopen(logfd, "w");
	if(logfile==NULL)
	{
		printf("failed to open erno is %i\n",errno);
		return 2;
	}
}
int MPI_Init_thread(int *argc, char ***argv, int required, int *provided)
{
	int r;
	r= PMPI_Init_thread(argc,argv,required,provided);
	init();
	if(profrank==0)
	{
		pthread_create(&powThread, NULL, power_measurement, NULL);
	}
	return r;
}
int MPI_Init(int *argc, char ***argv)
{
	int r;
	r=PMPI_Init(argc,argv);
	init();
	if(profrank==0)
	{
		pthread_create(&powThread, NULL, power_measurement, NULL);
	}

	return r;
}

int MPI_Finalize()
{
	int r;
	//printf("rank %i has finalized\n",profrank);
	monitoring=0;
	//fprintf(logfile,"monitoring ends in finalize %lu\n", ms_now()/1000);
	if(profrank==0)
	{
		pthread_join(powThread,NULL);
	}
	
	fclose(logfile);
	close(logfd);

	r=PMPI_Finalize();
	return r;
}
