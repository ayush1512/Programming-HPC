#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank, size, version, subversion;
	int data=0;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank == 0)
	{//Process 0 sends data to Process 1
		data = 9999;
		MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Process 0 sent data: %d \n", data);
	}
	else if(rank == 1)
	{	//Process 1 receives data from Process 0
		MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process 1 receied data:%d \n",data);
	}
	else if(rank==2)
	{
		printf("Process %d data: %d \n", rank,data);
	}
	else if(rank==3)
        {
                printf("Process %d data: %d \n", rank,data);
        }
		


	MPI_Finalize();
	return 0 ;
}
