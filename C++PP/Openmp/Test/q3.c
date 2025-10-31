#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int num = 10;
    int fact = 1;
    
    #pragma omp parallel for reduction(*:fact)
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    
    printf("Factorial of %i = %i\n", num, fact);

    return 0;
}