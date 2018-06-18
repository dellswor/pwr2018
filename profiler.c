#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <mpi.h>
#include <dlfcn.h>
#include <pthread.h>
#include <assert.h>

static int monitoring = 1;
static int writing = 1;

#include "time.c"
#include "file_streamer.c"
#include "powerprofiler.c"
#include "blocking_wrappers.c"

int main()
{
  return 0;
}

pthread_t powThread;
int profrank;
int MPI_Init_thread(int *argc, char ***argv, int required, int *provided)
{
 int r;
 // r=PMPI_Init(argc, argv);
r= PMPI_Init_thread(argc,argv,required,provided);

  MPI_Comm_rank(MPI_COMM_WORLD, &profrank);
//  printf("my rank is %i\n",profrank);
  char hostname[64];
  gethostname(hostname,64);
  char fname[100];
  sprintf(fname, "%s.dat", hostname);
  int start_rc = start_write(fname);
//printf("start rc: %i\n",start_rc);
//fflush(stdout);
  //printf("starting write\n");
  //fprintf(logfile, "start %lu\n", ms_now()/1000);
  if(profrank==0)
  {
    pthread_create(&powThread, NULL, power_measurement, NULL);
    //fprintf(logfile,"monitoring starts in init %lu\n", ms_now()/1000);
  }
return r;
}
int MPI_Init(int *argc, char ***argv)
{
  int r;
 // r=PMPI_Init(argc, argv);
r=PMPI_Init(argc,argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &profrank);
  //printf("my rank is %i\n",profrank);
  char hostname[64];
  gethostname(hostname,64);
  char fname[100];
  sprintf(fname, "%s.dat", hostname);
  int start_rc = start_write(fname);
//printf("start rc: %i\n",start_rc);
//fflush(stdout);
  //printf("starting write\n");
  //fprintf(logfile, "start %lu\n", ms_now()/1000);
  if(profrank==0)
  {
    pthread_create(&powThread, NULL, power_measurement, NULL);
    //fprintf(logfile,"monitoring starts in init %lu\n", ms_now()/1000);
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
  //fprintf(logfile,"end %lu\n", ms_now()/1000);
  end_write();
  r=PMPI_Finalize();
  return r;
}
