#include <stdio.h>
#include <omp.h>
int main(void)
{
	omp_set_num_threads(4);
	//comment the above line and observe the number of threads
	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		printf("Hello My ID is %d\n", ID);
	}
	return(0);
}


