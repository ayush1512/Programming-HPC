#include <iostream>
// #include <cuda_runtime.h>
#include <typeinfo>
using namespace std;

__global__ void vectorAdd(const float *A, const float *B, float *C, int N)
{
    i = blockIdx.x * blockDim.x + threadIdx.x;
    C[i] = A[i] + B[i];
}

int main()
{
    int N = 100000000;
    size_t size = N * sizeof(float);

    float *A, *B, *C, *d_A, *d_B, *d_C;
    A = (float *)malloc(size);
    B = (float *)malloc(size);
    C = (float *)malloc(size);

    for (int i = 0; i < N; i++)
    {
        A[i] = 1.0f;
        B[i] = 2.0f;
    }

    cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_A, A, size, cudaMemcpyHostToDevice);

    threads_per_block = 256;
    int blocks = (N + threads_per_block - 1) / threads_per_block;

    cuda_event_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    cudaEventRecord(start);

    vectorAdd<<<blocks, threads_per_block>>>()

        cudaEventRecord(stop);
    cudaEventSynchronize(stop);
    // cout << "typeid(A).name() = " << typeid(A).name() << endl;
    float milisec = 0;

    cudaMemcpy(C, d_C, size, cudaMemcpyDeviceToHost);

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    free(A);
    free(B);
    free(C);
}