#include<stdio.h>
#include<omp.h>

int main(void)
{
	omp_set_num_threads(4);
	//int i=0;	
	#pragma omp parallel for
	for(int i=0;i<10;i++)
	{
		printf("thread %d is processing iteration %d\n",omp_get_thread_num(),i);
//sentinal mop directive format
	}	
	return(0);
}
