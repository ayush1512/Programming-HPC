
def main():
    from mpi4py import MPI
    comm = MPI.COMM_WORLD
    rank = comm.Get_rank()
    size = comm.Get_size()
    print(f' Process {rank} out of {size} is alive")
    
if __name__ == '__main__':
    main()
