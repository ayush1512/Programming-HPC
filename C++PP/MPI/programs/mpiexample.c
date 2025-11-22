#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    double starttime, endtime;
    starttime = MPI_Wtime();

    if (rank == 0)
    {
        /* Rank 0 sends an integer to each of the other process ranks */
        int i;
        int value = 0;
        for (i = 1; i < size; i++)
        {
            value = value + i;
            MPI_Send(&value, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            // MPI_Send(void* buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
        }
    }
    else
    {
        /* All other process ranks receive one number from Rank 0 */
        int value;
        MPI_Status status;
        MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        // MPI_Recv(void* buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status)
        printf("Rank %d received value %d\n", rank, value);
        endtime = MPI_Wtime();
        printf("Total run time: %f seconds\n", endtime - starttime);
    }
    MPI_Finalize();
    return 0;
}