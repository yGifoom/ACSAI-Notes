#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv){
    int n = atoi(argv[1]);

    int size, rank;
    // initialize mpi
    MPI_Init(NULL, NULL);

    float start_time = MPI_Wtime();

    // set the communicator, where size is the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // set the rank of process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // every process will execute this piece of code
    srand(time(NULL) + rank);

    int in_circle = 0;
    float x, y;

    int iterations = n/size;
    for (int i = 0; i<iterations; i++){

        x = rand() / (float) RAND_MAX; // TODO: try with double
        y = rand() / (float) RAND_MAX;

        //printf("this is x,y: %f,%f", x,y);
        if (x*x + y*y < 1){
            in_circle ++;
        }
    }

    // target output
    int res;

    MPI_Reduce(&in_circle, &res, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // calculate pi
    if (rank == 0){
        double pi = (res*4)/ (float)(n*size);
        float total_time = MPI_Wtime() - start_time;
        printf("this is pi:%f, calculated in %f\n",pi, total_time);
    }

    MPI_Finalize();
    return 0;

}