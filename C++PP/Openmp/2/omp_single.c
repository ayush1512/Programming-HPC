#include <stdio.h>
#include <omp.h>


int main() 
{
	int i ;
	double t0 = omp_get_wtime();
	#pragma omp parallel num_threads(4) 
	{
		int ID = omp_get_thread_num() ;
		#pragma omp single // #pragma omp master
		{
			for(i =0 ; i < 10000000 ; i++){}
		}

		printf("Threads [%d]\n", ID) ;
	}
	printf("%f",omp_get_wtime() - t0);

	return 0 ;
}
