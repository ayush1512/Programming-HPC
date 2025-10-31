# Broadcast using mpi4py

from mpi4py import MPI
comm = MPI.COMM_WORLD
rank = comm.Get_rank()

data = None

if rank == 0:
	data = {" Val1": 10}

ret_data = comm.bcast(data, root = 0)
print(rank, " got the data: ", ret_data)