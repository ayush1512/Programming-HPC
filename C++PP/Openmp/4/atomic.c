#include<stdio.h>
#include<omp.h>
//atomic - example
//atomic for accessing specifc memory location and race condition avoidance
//used for update of memory location
int main(void)
{
	int count=0 , dec=20;

	#pragma omp parallel num_threads(20)
	{
		#pragma omp atomic
		count++;
	//	#pragma omp atomic
	//	dec--; 

	} 

	printf("count = %d\n" , count);
	//printf("dec=%d\n" , dec);

//Difference in result with and without critical section is coz ultiple thread is trying simultaneously update the same variable, atomic constructs ensure that only one thread updates 
}
