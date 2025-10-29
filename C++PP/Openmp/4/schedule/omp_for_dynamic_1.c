#include <stdio.h>
#include <omp.h>

int main()
{
	int i;
	omp_set_num_threads(4);
	#pragma omp parallel for schedule(dynamic, 2) 	
	for (i = 0; i < 20; i++)
	{
		printf("Thread %d is running number %d\n", omp_get_thread_num(), i);
	}
	return 0;
}
