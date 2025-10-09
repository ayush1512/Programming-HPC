# Multiprocessing
from multiprocessing import Process, Pool
import time

def square(n): 
    time.sleep(2)
    print(n**2)
    
def cube(n): 
    time.sleep(2)
    print(n**3)

p1 = Process(target=square, args=(4, ))
p2 = Process(target=cube, args=(5, ))

p1.start()
p2.start()

time.sleep(1)

print("+- "* 25)
p1.join()
p2.join()
    