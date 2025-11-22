#include <iostream>
#include <cuda_runtime.h>


// kernel/device-side

__global__ void  addOneKernel( int *d, int n){
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if ( i <= n){
		d[i] += 1;
	}
}


// host/core (cpu) side
int main(){
	int const N = 16;
	int * dArray;

	cudaMalloc( &dArray, (N) * sizeof(int) ); // Allocated contigeous memory of 16 integers for Kernel/Device-side

	// int Array[N] = { 0, 0, 0,...}; // 16 times // scaller-way-of-initialization
	//int Array[N]  {0}; // uniform/universal-initialization
	int hArray[N] = {0}; // uniform/universal-initialization

	cudaMemcpy( dArray, hArray, N * sizeof(int), cudaMemcpyHostToDevice);

	// kernel?
	addOneKernel<<<2, 8>>> (dArray, N); // In 2-cores launces 8 threads => total 16 threads

	cudaDeviceSynchronize();
	cudaMemcpy( hArray, dArray, N * sizeof(int), cudaMemcpyHostToDevice);

	for( int i=0; i<N; i++)
		std::cout<<"hArray[ "<< i<<"] = "<< hArray[i]<<", ";
	std::cout<<"\n";

	cudaFree( dArray);
	return 0;
}
