#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 1000

int main()
{
    int a[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
    }
    int sum = 0;
#pragma omp parallel for reduction(+ : sum) num_threads(4) schedule(static)
    for (int i = 0; i < N; i++)
    {
        int tid = omp_get_thread_num();
        printf("Iteration %i processed by Thread %i\n", i, tid);
        sum += a[i];
    }
    printf("Sum is: %d", sum);
    return 0;
}