#include<stdio.h>
#include<omp.h>

int main(void)
{
	//here we are not mentioning the no of threads, so how many threads will be spanned?? basically the processor on which it is running will define, suppose node with 16 cores then , 16 threads are spanned
	#pragma omp parallel 
	{
		//printf("Parallel region\n");
		printf("Parallel REgion by %d\n", omp_get_thread_num());
	}
	printf("serial Region\n");
	return(0);
	//export OMP_NUM_THREADS=5 and will be available in the session
}
