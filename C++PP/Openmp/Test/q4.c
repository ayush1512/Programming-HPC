#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int n = 10;
    int arr[10];

    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int min, max;

    min = arr[0];
    max = arr[0];

#pragma omp parallel
    {
        int tmin = arr[0];
        int tmax = arr[0];

#pragma omp for nowait
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < tmin)
                tmin = arr[i];
            if (arr[i] > tmax)
                tmax = arr[i];
        }

#pragma omp critical
        {
            if (tmin < min)
                min = tmin;
            if (tmax > max)
                max = tmax;
        }
    }
 
    printf("Min. value = %d\n", min);
    printf("Max. value = %d\n", max);

    return 0;
}