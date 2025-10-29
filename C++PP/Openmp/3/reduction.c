#include<stdio.h>

#include<omp.h>

int main(void)
{
	int sum=0 , i;
	double t0 = omp_get_wtime();
	#pragma omp parallel for reduction(+:sum)
	for(i=1 ; i<=100000000 ; i++)
	{ 
		sum = sum + i;

	} 

	printf("sum = %d\n" , sum);
	printf("Time taken: %f",omp_get_wtime()-t0);
}
