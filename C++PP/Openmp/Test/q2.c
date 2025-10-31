#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int b[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}};

    int result[3][3] = {0};
    int i, j;

#pragma omp parallel for schedule(static)
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
#pragma omp barrier

    printf("Resultant matrix: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%i ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}