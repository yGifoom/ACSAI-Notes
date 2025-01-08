#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


int *A, *B, *C;
int rows, cols;
int n_thread;

void* mat_mul(void * in_put){
    int id = *(int*) in_put;

    int my_rows = rows/n_thread;
    int my_i = my_rows*id;
    int *tmp = malloc(sizeof(int)*cols);

    for(int i=0; i<my_rows; i++, my_i++){
        for(int j = 0; j < cols; j++){
            C[my_i *] = A[my_i*cols + j] * B[i*rows + j];

        }
    }
        

}

int * sum_v(int* row_to_mul, int* column_to_mul){
    for(int i = 0; i<rows; i++){
        C[]
    }
}

int main(int arc, char** argv){
    if (arc < 4){
        fprintf(stderr, "Usage %s: <number of threads>, <number of columns>, <number of rows>", argv[0]);
        return 1;
    }

    n_thread = strtol(argv[1], NULL, 10);
    int *ids = malloc(sizeof(int) * n_thread);
    pthread_t *handles = malloc(sizeof(pthread_t) * n_thread);

    // create matrix
    cols = strtoll(argv[2], NULL, 10);
    rows = strtoll(argv[3], NULL, 10);

    A = malloc(sizeof(int)*rows*cols); // put contiguously rows
    B = malloc(sizeof(int)*cols*rows); // put contiguously columns
    C = malloc(sizeof(int) * rows * rows);

    // create the threads
    void* matrix_mul(void*);

    for(int i = 0; i<n_thread; i++){
        ids[i] = i;
        pthread_create(handles[ids[i]], 
        NULL, matrix_mul, (void*) &ids[i]);
    }
}