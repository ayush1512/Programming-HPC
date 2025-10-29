#include <stdio.h>
#include <omp.h>

//In this example set the number of threads using environment variables
// export OMP_NUM_THREADS =5

int main()
{
	#pragma omp parallel
	{
		 printf("I am thread %d of Threads %d\n", omp_get_thread_num(), omp_get_num_threads());
	}
}
