#include <mpi.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
      sleep(20);
    }
    // Finalize the MPI environment.
    MPI_Finalize();
}
