#include <mpi.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
  if(n==0)
    return 0;
  else if(n==1)
    return 1;
  else
    return fib(n-1)+fib(n-2);
}

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);


    // Get the number of processes
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Get the rank of the process
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int *ranks = (int *)malloc(size*sizeof(int));
    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Gather(&rank, 1, MPI_INT, ranks, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    if(rank==0)
    {
      int sum=0;
      for(int i=0; i<size*size; i++)
      {
        sum+=fib(i);
      }
      printf("APP OUTPUT: result is %i\n",sum);
    }

    // Finalize the MPI environment.
    MPI_Finalize();
}
