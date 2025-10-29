import multiprocessing
import time 
import os

process_id = os.getpid()

def task(name, delay):
    print(f"Process {process_id} is starting task '{name}'.....")
    time.sleep(delay)
    print(f"Process {process_id} is finished task ..... '{name}'")

if __name__ == '__main__':
    print(f"Main process starting having PID .... {process_id}")

    p1 = multiprocessing.Process(target=task, args=("one",5))
    p2 = multiprocessing.Process(target=task, args=("two",10))

    p1.start()
    p2.start()

    p1.join()
    p2.join()

    print("All processes finished.")