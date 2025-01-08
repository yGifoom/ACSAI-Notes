#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double get_rand(unsigned *seed){
    return rand_r(seed) / (double) RAND_MAX;
}

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    double x, y, tmp;
    srand(time(NULL));
    unsigned sum = 0;
    double start = omp_get_wtime();

    #pragma parallel
    {
        unsigned seed = omp_get_thread_num();
        #pragma omp single //to create a barrier
            printf(" %d threads \n",seed);   

        #pragma omp for reduction(+:sum) private(x,y,tmp)
        for (int i = 0; i<n ; i++){
            x = get_rand(&seed);
            y = get_rand(&seed);

            tmp = x*x+y*y;
            if (tmp < 1){
                sum ++;
            }
        }
    }
    double total = omp_get_wtime() - start;
    
    double pi = (sum*4)/ (double) (n);
    printf("pi was estimated as %lf in %lf\n", pi, total);
}