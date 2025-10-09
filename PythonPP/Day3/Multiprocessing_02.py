from multiprocessing import Process, Pool
import time

def square(n):
	return n * n

with Pool(5) as pool:
    print( pool.map( square, [1,2,3,4,5]))