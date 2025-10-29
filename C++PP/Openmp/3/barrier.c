#include <stdio.h>
#include <omp.h>

#define size 200

int main(void)
{
	int a[size], b[size], i;

	for (i = 0; i < size; i++)
		a[i] = 0;

#pragma omp parallel private(i)
	{
		int tid = omp_get_thread_num();

		// if (tid == 2)
		// {
		// 	for (i = 0; i < size; i++)
		// 		a[i] = 1;
		// }

		// To get only updation on Thread 2 Chunk or Thread 2 working on only the scheduled chunk instead of others' chunk
		#pragma omp for schedule(static)
        for (i = 0; i < size; i++)
            if (omp_get_thread_num() == 2)
                a[i] = 1;

#pragma omp barrier

#pragma omp for
		for (i = 0; i < size; i++)
			b[i] = a[i] * 2;
	}

	for (i = 0; i < size; i++)
		printf("b[%d] = %d\n", i, b[i]);
}
