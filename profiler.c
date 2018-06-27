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

static int monitoring =0;
int globalRank=-1;
int localRank = -1;
int nodeID = -1;
static char config[10][100];
#include "pwr.h"
#include "time.c"
#include "powerprofiler.c"
int main()
{
	return 0;
}

pthread_t powThread;
int logfd;
FILE *logfile=NULL;
#include "mpi_wrappers.c"


int init()
{
	MPI_Comm_rank(MPI_COMM_WORLD, &globalRank);
	fflush(stdout);
	localRank = atoi(getenv("SLURM_LOCALID"));
	char fname[100];
	nodeID=globalRank-localRank;

	FILE *configf = NULL; 
	int i = 0;
	int total = 0;

	configf = fopen("profiler.config", "r");
	while(fgets(config[i], 100, configf)) {
		config[i][strlen(config[i]) - 1] = '\0';
		i++;
	}
	printf("------------\n");
	printf("Profiler Configuration\n");
	printf("output path: %s\n",config[0]);
	printf("powercap: %s watts\n",config[1]);
	printf("time window: %s seconds\n",config[2]);
	printf("monitoring frequency: %s nano seconds\n",config[3]);
	printf("------------\n");
	sprintf(fname, "%s/functions.%d.%d.dat",config[0],localRank, nodeID);
	struct stat st;
	if (stat(config[0], &st) == -1) {
		mkdir(config[0], 0700);
	}
	if(localRank == 0 ) {
		pthread_create(&powThread, NULL, power_measurement, NULL);

	}
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
	fflush(stdout);
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
	//printf("rank %i has finalized\n",profrank);
	monitoring=0;
	//fprintf(logfile,"monitoring ends in finalize %lu\n", ms_now()/1000);
	if(localRank==0)
	{
		pthread_join(powThread,NULL);
	}

	fclose(logfile);
	close(logfd);

	r=PMPI_Finalize();
	return r;
}
