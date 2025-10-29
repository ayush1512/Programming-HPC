#include<stdio.h>
#include<omp.h>

int main(void)
{
//How many threads to be created for that api is there omp_set_num_threads
	omp_set_num_threads(6); //set the num of threads in parallel region
	//before pragma its join, within pragma fork and after that also join
	#pragma omp parallel num_threads(7)
	{
		int ID = omp_get_thread_num(); //returns the unique thread ID
		printf("Hello my ID is %d\n", ID);
	}
	return(0);
	//now to comiple, we need to use switch gcc -fopenmp demo2.c -o demo2.out
	//out is in random orde, 0th is the master thread
	//here join is impplicit, other wise barrier is the construct for the join
}
