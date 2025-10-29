#include <stdio.h>
#include <omp.h>
int main(){
        omp_set_num_threads(1000);
        #pragma omp parallel
        {
                int ID = omp_get_thread_num();
                printf("Hello my ID is: %d\n", ID);
        }
        return 0;
}

// export OMP_NUM_THREADS=5
// clang++ -Xpreprocessor -fopenmp \
  -I/opt/homebrew/opt/libomp/include \
  -L/opt/homebrew/opt/libomp/lib -lomp \
  2.c -o 2
