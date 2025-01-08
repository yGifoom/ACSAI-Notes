// File : test.cu
#include <stdio.h>
#include <cuda.h>

__global__ void hello()
{
    printf("cuda capable\n");
}

int main()
{
    hello<<<1,10>>>();
    cudaDeviceSynchronize();
    return 1;
}