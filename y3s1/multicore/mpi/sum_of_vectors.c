#include<mpi.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

double serial_sum(int len){
    int *A = (int*)malloc(len * sizeof(int));
    int *B = (int*)malloc(len * sizeof(int));

    for(int i = 0; i<len; i++){
        A[i] = rand()%10;
        B[i] = rand()%10;
    }

    double start = MPI_Wtime();
    for(int i = 0; i<len; i++){
        A[i] += B[i];
    }
    double elapsed = MPI_Wtime() - start;
    printf("seq_time for same execution was %e s", elapsed);

    free(A);
    free(B);
    return elapsed;
}

double parallel_sum(int len){
    int size, rank;

    // set the communicator, where size is the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // set the rank of process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int *A = (int*) malloc(sizeof(int));
    int *B = (int*) malloc(sizeof(int));

    if (rank == 0){
        A = (int*) realloc(A, len * sizeof(int)); 
        B = (int*) realloc(B, len * sizeof(int));

        for(int i = 0; i<len; i++){
            A[i] = (int) rand() % 10;
            B[i] = (int) rand() % 10;
        }
        /*
        printf("\narray A:");
        for(int i = 0; i<len; i++){
            printf("%d,",A[i]);
        }

        printf("\narray B:");
        for(int i = 0; i<len; i++){
            printf("%d,",B[i]);
        }*/

    }
    
    int llen = (int) len/size;
    int *lA = (int*) malloc(llen * sizeof(int)); 
    int *lB = (int*) malloc(llen * sizeof(int));

    MPI_Barrier(MPI_COMM_WORLD);
    double start = MPI_Wtime();

    if (rank == 0){
        MPI_Scatter(A, llen, MPI_INT, MPI_IN_PLACE, llen, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Scatter(B, llen, MPI_INT, MPI_IN_PLACE, llen, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else{
        MPI_Scatter(NULL, llen, MPI_INT, lA, llen, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Scatter(NULL, llen, MPI_INT, lB, llen, MPI_INT, 0, MPI_COMM_WORLD);
    }

    if (rank == 0){
        for(int i= 0; i< llen; i++){
        A[i] += B[i];
        }
    }
    else{
        for(int i= 0; i< llen; i++){
        lA[i] += lB[i];
        }
    }
    /*
    if (rank == 0){
        printf("\narray A0:");
        for(int i= 0; i< llen; i++){
        printf("%d,",A[i]);
        }
        printf("\n");
    }
    else{
        printf("\narray A%d:", rank);
        for(int i= 0; i< llen; i++){
        printf("%d,",lA[i]);
        }
        printf("\n");
    }*/

    if (rank == 0){ //GATHER brakes if you put null in send buffer, even if it doesn't use it
        MPI_Gather(A, llen, MPI_INT, A, llen, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else{
        MPI_Gather(lA, llen, MPI_INT, NULL, llen, MPI_INT, 0, MPI_COMM_WORLD);
    }
    double elapsed = MPI_Wtime() - start;
    double max_time;
    /*
    if (rank == 0){
        printf("\narray A0:");
        for(int i= 0; i< len; i++){
        printf("%d,",A[i]);
        }
        printf("\n");
    }
    */
    
    MPI_Reduce(&elapsed, &max_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    if(rank==0){
        printf("time for parallel execution was %e s\n", max_time);
    }

    free(A);free(B);free(lA);free(lB);
    return max_time;
}

int main(int argc, char** argv){
    // initialize
    MPI_Init(NULL, NULL);
    srand(time(NULL));

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int len = atoi(argv[1]);
    double parall_time = parallel_sum(len);
    if (rank == 0){
        double seq_time = serial_sum(len);
        // metrics
        double speedup =  seq_time/parall_time;
        //double scalability = 
        printf("\nspeedup for a problem of dim:%d is:%e s with processes %d\n", len, speedup, size);

    }

    MPI_Finalize();

}

