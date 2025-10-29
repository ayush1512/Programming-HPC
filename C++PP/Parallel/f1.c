#include <stdio.h>
#include <omp.h>

int main(void){
    int i;
    #pragma omp parallel num_threads(4)
    {
        int ID = omp_get_thread_num();
        if(ID == 0){
            printf("Master Thread\n");
        }else{
            printf("Hello my ID is: %d\n", ID);
        }
    }
    return 0;
}