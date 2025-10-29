#include <stdio.h>
#include <omp.h>

#define SIZE 10

void fun1()
{
	printf("I am in fun1\n");
}

void fun2()
{
	printf("I am in fun2\n");
}
void fun3()
{
	printf("I am in fun3\n");
}

int main()
{

#pragma omp parallel
	{
		int ID = omp_get_thread_num();

		// #pragma omp for nowait
		// 		for (int i = 0; i < SIZE; i++)
		// 		{
		// 			printf("Thread %d\n", ID);
		// 		}

#pragma omp sections
		{
#pragma omp section
			{
				// int ID = omp_get_thread_num(); //returns the unique thread ID
				printf("Hello my ID is %d\n", ID);
				fun1();
			}
#pragma omp section
			{
				printf("Hello my ID is %d\n", ID);
				fun2();
			}

#pragma omp section
			{
				printf("Hello my ID is %d\n", ID);
				fun3();
			}
		}
// #pragma omp barrier
	}

	return 0;
}
