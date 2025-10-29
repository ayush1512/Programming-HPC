#include <stdio.h>
#include <omp.h>

#define size 120

int main(void)
{
	int a[size], b[size], i;

	for (i = 0; i < size; i++)
		a[i] = 0;

#pragma omp parallel num_threads(10)
	{
		int tid = omp_get_thread_num();
#pragma omp for
		for (i = 0; i < size; i++)
		{
			if (tid == 2)
				a[i] = 1;
		}
#pragma omp master
		printf("before barrier\n");

		// #pragma omp barrier

#pragma omp for nowait
		for (i = 0; i < size; i++)
			printf("b[%d] = %d\n", i, b[i]);
		// for (i = 0; i < size; i++)
		// 	b[i] = a[i] * 2;
	}
}
