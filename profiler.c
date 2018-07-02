#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <dlfcn.h>
#include <pthread.h>
#include <assert.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

static int monitoring =1;
int globalRank=-1;
int localRank = -1;
int nodeID = -1;
static char config[10][100];
pthread_t powThread;
int logfd;
FILE *logfile=NULL;

#include "pwr.h"
#include "time.c"
#include "powerprofiler.c"
#include "mpi_wrappers.c"
int main()
{
	return 0;
}



int init()
{
	MPI_Comm_rank(MPI_COMM_WORLD, &globalRank);
	fflush(stdout);
	localRank = atoi(getenv("SLURM_LOCALID"));
	char fname[100];
	nodeID=globalRank-localRank;

	FILE *configf = NULL; 
	int i = 0;
	configf = fopen("profiler.config", "r");
	while(fgets(config[i], 100, configf)) {
		config[i][strlen(config[i]) - 1] = '\0';
		i++;
	}
	if(globalRank==0){
		printf("------------\n");
		printf("Profiler Configuration\n");
		printf("output path: %s\n",config[0]);
		if(atoi(config[1])==-1)
		{
			printf("powercap set to TDP of socket\n");
		}
		else
		{
			printf("powercap: %s watts\n",config[1]);
		}
		printf("time window: %s seconds\n",config[2]);
		printf("monitoring frequency: %s nano seconds\n",config[3]);
		printf("------------\n");
	}
	sprintf(fname, "%s/functions.%d.%d.dat",config[0],localRank, nodeID);
	logfd=open(fname,O_WRONLY|O_CREAT|O_NDELAY, S_IRUSR|S_IWUSR);
	if(logfd<0)
	{
		printf("Failed to get output file descriptor. %s\n",strerror(errno));
		fflush(stdout);
		exit(EXIT_FAILURE);	
	}
	logfile = fdopen(logfd, "w");
	if(logfile==NULL)
	{
		printf("Failed to open output file for write. %s\n",strerror(errno));
		fflush(stdout);
		exit(EXIT_FAILURE);
	}
	if(localRank == 0 ) {
		if(pthread_create(&powThread, NULL, power_measurement, NULL)!=0)
		{
			printf("powerprofiler thread failed to start\n");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
int MPI_Init_thread(int *argc, char ***argv, int required, int *provided)
{
	int r;
	r= PMPI_Init_thread(argc,argv,required,provided);
	init();
	return r;
}
int MPI_Init(int *argc, char ***argv)
{
	int r;
	r=PMPI_Init(argc,argv);
	init();
	return r;
}

int MPI_Finalize()
{
	int r;
	monitoring=0;
	for(int i=0; i<num_sockets(); i++)
	{
		struct rapl_power_info raplinfo;
		get_rapl_power_info(i, &raplinfo);
		double tdp = raplinfo.pkg_therm_power;
		printf("Rank %d: Resetting power limit to %lf for socket %d\n",globalRank, tdp, i);
		struct rapl_limit rlim;
		rlim.watts = tdp;
		rlim.seconds = 1;
		rlim.bits = 0;
		set_pkg_rapl_limit(i, &rlim,&rlim);
	}
	if(localRank==0)
	{
		pthread_join(powThread,NULL);
	}

	fclose(logfile);
	close(logfd);

	r=PMPI_Finalize();
	return r;
}
