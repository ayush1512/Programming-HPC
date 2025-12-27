#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    int token;
    if (world_rank != 0) {
        // Receive from the previous rank
        MPI_Recv(&token, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Node %s (Rank %d) received token %d from Rank %d\n", 
               processor_name, world_rank, token, world_rank - 1);
    } else {
        // Master node starts the token at 0
        token = 0;
        printf("Master Node %s (Rank %d) started the ring.\n", processor_name, world_rank);
    }

    // Increment and send to the next rank
    token++;
    MPI_Send(&token, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);

    // The master node eventually receives the token back from the last node
    if (world_rank == 0) {
        MPI_Recv(&token, 1, MPI_INT, world_size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Master Node %s received token %d back from Rank %d. Test PASSED!\n", 
               processor_name, token, world_size - 1);
    }

    MPI_Finalize();
    return 0;
}