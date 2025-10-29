#include<stdio.h>
#define N 11
//To find sum of N array elements

int main(void)
{
	int a[N];
	int sum=0;
	int i=0;	
	for(i=1;i<N;i++)
	{ 
		a[i]=i;
		printf("array element : %d\n",a[i]);
	}
	

	for(i=1;i<N;i++)
	{
		sum += a[i];
	}
	printf("SUM: %d\n",sum);
//How to create a parallel openmp code without creating conflicts with sum
}

