#include<stdio.h>
#include<omp.h>

int main(void)
{
//	#pragma omp parallel num_threads(2)
//	{
//		int ID = omp_get_thread_num();
//		printf("Hello from Me\n");
//	}
//
	omp_set_num_threads(4);
	int i=0;	
	#pragma omp parallel //for 	
	for(i=0;i<10;i++)
	{
		printf("thread %d is processing iteration %d\n",omp_get_thread_num(),i);
	}	
	return(0);	
}
