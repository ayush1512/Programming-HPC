#include <stdio.h>

#include <omp.h>

#define size 10

int main(void)
{
	int tid, i, j = 2;

	int a[size], numt = 100;

	for (i = 0; i < size; i++)
		a[i] = 1;

#pragma omp parallel num_threads(5) private(tid, i, j) shared(a, numt)
	{
		tid = omp_get_thread_num();

		if (tid == 2)
		{
			numt = omp_get_num_threads();
			printf("numt = %d , tid=%d\n", numt, tid);
		}

// #pragma omp barrier

		printf("tid = %d , j = %d\n", tid, j);
		printf("Numt of tid  %d is %d\n ", tid, numt + 50);
		//		#pragma omp for
		//		for(i=0 ; i<size ; i++)
		//		a[i] = a[i] * j;
	}

	//		for(i=0 ; i<size ; i++)
	//		printf("a[%d] = %d\n" , i , a[i]);
}
