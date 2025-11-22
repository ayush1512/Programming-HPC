#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv){
        int rank ,size;
        int a=10, b=10;
        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        if(rank == 0){
                printf("a-b = %d\n",a-b);
        }else if(rank == 1){
                printf("a+b = %d\n",a+b);
        }else{
                printf("a*b = %d\n",a*b);
        }
        MPI_Finalize();
}
