#include <stdio.h>
#include <omp.h>

int main(){
    int a[5], i;
    omp_set_num_threads(5);
    #pragma omp parallel
    {
        #pragma omp for
        for(i = 0; i < 5; i++)
            a[i] = i*i;
        #pragma omp master
        // #pragma omp single
        for(i=0;i<5;i++)
            printf("a[%d] - %d\n", i, a[i]);

        #pragma omp for
        for(i=0;i<5;i++)
            a[i] += i;
    }
    return 0;
}