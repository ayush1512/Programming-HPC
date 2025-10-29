#include<stdio.h>
#include<omp.h>
#define N 11
//To find sum of N array elements

int main(void)
{
	int a[N];
	int sum=0;
	int i=0;	
	for(i=0;i<N;i++)
	{ 
		a[i]=i;
		printf("array element : %d\n",a[i]);
	}
//	omp_set_num_threads(4);
	#pragma omp parallel for num_threads(4)
	for(i=0;i<N;i++)
	{
		#pragma omp critical
		{	
			sum += a[i];
		}
	}
	printf("SUM: %d\n",sum);
//How to create a parallel openmp code without creating conflicts with sum
}

