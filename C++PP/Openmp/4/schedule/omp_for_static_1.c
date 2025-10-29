#include <stdio.h>
#include <omp.h>

int main()
{
	int i;
	omp_set_num_threads(6);
	#pragma omp parallel for schedule(static, 3) 	
	for (i = 0; i < 20; i++)
	{
		printf("Thread %d is running number %d\n", omp_get_thread_num(), i);
	}
	return 0;
}
