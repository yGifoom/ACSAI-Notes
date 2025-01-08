#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

int thread_c;
long long precision;

void* estimate(void* in){
    int rank =  *((int*) in);
    double *partial_sum = malloc(sizeof(double));
    *partial_sum = 0.0;

    long long responsability = precision / (long long) thread_c;
    long long my_i = responsability * rank;
    double sign;

    printf("my_i is %lld, rank is %d\n", my_i, rank);
    if (my_i % 2 == 0){
        sign = 1.0;
    }
    else{
        sign = -1.0;
    }

    for(int i = 0; i<responsability; i++, sign = -sign, my_i ++){
        *partial_sum += (double) (sign / (double)(2*my_i+1));
    }
    printf("thread %d exiting wh sum %lf...\n", rank, *partial_sum);

    return (void*) partial_sum;
} /*estimate*/

int main(int argc, char** argv){

    if (argc < 3) {  // Check if both arguments are provided
        fprintf(stderr, "Usage: %s <thread_count> <precision>\n", argv[0]);
        return 1;
    }

    thread_c = strtoll(argv[1], NULL, 10);
    pthread_t *handles = malloc(sizeof(pthread_t) * thread_c);

    precision = strtoll(argv[2], NULL, 10);
    void* estimate(void*);

    int *ids = malloc(sizeof(int) * thread_c);
    
    // start the threads
    for(int thread = 0; thread<thread_c; thread ++){
        ids[thread] = thread;
        pthread_create(&handles[thread], 
        NULL,
        estimate,
        (void *) &ids[thread]); //TODO fare array di hanle di thread o trova soluzione per crisi identitaria thread
    }

    // get the result
    void *out;
    double pi = 0.0;
    for(int thread = 0; thread<thread_c; thread ++){
        pthread_join(handles[thread], &out);
        pi += *((double *) out);
    }

    pi = (double) 4*pi;

    printf("pi was evaluated to %lf\n", pi);
    free(handles);
    return 0;
}