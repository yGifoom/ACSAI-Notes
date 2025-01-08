// example of ring mulitprocesses

#include <stdio.h>
#include <mpi.h>

int main(void){
    int rank, size;
    int send_rg = 13;
    int send_lf = 56;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    // array of requests
    MPI_Request requests[4];

    // send
    MPI_Isend(&send_right, 1, MPI_INT, (rank+1) % size, 0, MPI_COMM_WORLD, &requests[0]);
    // send_right = 99 // risk of writing buffer before the Isend made a copy, it is non blocking
    MPI_Isend(&send_left, 1, MP_INT, (rank-1) % size, 0, MPI_COMM_WORLD, &requests[1]);

    // recieve 
    MPI_Irecv(&recv_right, 1, MP_INT, (rank+1) % size, 0, MPI_COMM_WORLD, &requests[2]);
    MPI_Irecv(&recv_left, 1, MP_INT, (rank-1) % size, 0, MPI_COMM_WORLD, &reqiests[3]);
    
    // COMPUTE TIME

    // wait for everything to be done
    MPI_Waitall(4, requests, MPI_STATUS_IGNORE)

    MPI_Finalize();
}