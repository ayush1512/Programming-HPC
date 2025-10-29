#include <stdio.h>

#include <omp.h>


int main()
{
        int i ;

        // omp_set_num_threads(8) ;
        printf("No. of processors: %d\n",omp_get_num_procs());
        #pragma omp parallel num_threads(4)
        {
                printf("Hello from FDP\n") ;

        }

        return 0 ;
}

