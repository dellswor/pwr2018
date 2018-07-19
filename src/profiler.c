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
char hostname[64];
pthread_t powThread;
int logfd;
FILE *logfile=NULL;
char pathname[100];

#include "pwr.h"
#include "time.c"
#include "powerprofiler.c"
void writeAndFormat(long unsigned time, const char *funcname, int moment)
{
	fprintf(logfile, "%lu %s %d\n", time, funcname, moment);
}
#if WRAPPER_TOG==1
#include "mpi_wrappers.c"
#endif
int main()
{
	return 0;
}



int init()
{
	MPI_Comm_rank(MPI_COMM_WORLD, &globalRank);
	if(getenv("SLURM_LOCALID")!=NULL)
	{
		localRank = atoi(getenv("SLURM_LOCALID"));
	}
	else if(getenv("OMPI_COMM_WORLD_LOCAL_RANK")!=NULL)
	{
		localRank = atoi(getenv("OMPI_COMM_WORLD_LOCAL_RANK"));
	}
	else
	{
		printf("Use either mpirun or srun for local rank environmental variable.\n");
		exit(EXIT_FAILURE);
	}
	char fname[100];
	gethostname(hostname,64);


	if(getenv("PROFILER_OUTPUT_SUFFIX")==NULL)
	{
		sprintf(pathname, "%s",getenv("PROFILER_OUTPUT_PATH"));
	}
	else
	{
		sprintf(pathname, "%s%s",getenv("PROFILER_OUTPUT_PATH"),getenv("PROFILER_OUTPUT_SUFFIX"));
	}
	sprintf(fname,"%s/functions.rank%d.%s.dat",pathname,localRank,hostname);
	if(globalRank==0){
		printf("------------\n");
		printf("Profiler Configuration\n");
		printf("output path: %s\n",pathname);
		printf("monitoring frequency: %s nano seconds\n",getenv("PROFILER_FREQUENCY"));
		printf("------------\n");
	}
	logfd=open(fname,O_WRONLY|O_CREAT|O_NDELAY, S_IRUSR|S_IWUSR);
	if(logfd<0)
	{
		printf("open failed in %s. %s\n",__FILE__,strerror(errno));
		exit(EXIT_FAILURE);	
	}
	logfile = fdopen(logfd, "w");
	if(logfile==NULL)
	{
		printf("fdopen failed in %s. %s\n",__FILE__,strerror(errno));
		exit(EXIT_FAILURE);
	}
	if(localRank == 0 ) {
		if(pthread_create(&powThread, NULL, power_measurement, NULL)!=0)
		{
			printf("pthread_create failed in %s.\n",__FILE__);
			exit(EXIT_FAILURE);
		}
	}
	fprintf(logfile, "time(ms) function_name moment\n");
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


	fclose(logfile);
	close(logfd);

	r=PMPI_Finalize();
	fflush(stdout);
	monitoring=0;

	fflush(stdout);
	if(localRank==0)
	{
		//pthread_join(powThread,NULL);
	}
	fflush(stdout);
	return r;
}
