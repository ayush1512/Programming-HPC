#include<stdio.h>
#include<omp.h>
#define N 1001
//To find sum of N array elements

int main(void)
{
	int a[N];
//	int sum_local=0;
	int sum_shared=0;
	int i=0;	
	for(i=0;i<N;i++)
	{ 
		a[i]=i;
		printf("array element : %d\n",a[i]);
	}
	// omp_set_num_threads(4);
	#pragma omp parallel
	{
		int sum_local=0;
		#pragma omp for nowait
		for(i=0;i<N;i++)
		{
			sum_local += i;
		}
		#pragma omp critical
		{	
			sum_shared +=sum_local;	
		}	
	}
	printf("SUM SHARED: %d\n",sum_shared);
//How to create a parallel openmp code without creating conflicts with sum
}

