
import os
import multiprocessing

def OtherProcess_Start():
    print(" Other Process start ---")
    print('   other-process: os.getpid() = ', os.getpid())
    print(' other-process: os.getppid() = ', os.getppid())
    print(" Other Process end ---")

# Main-Process
def main():
    

    print("Parent process start")
    
    print(' Main Thread: os.getpid() = ', os.getpid())
    print(' Main Thread: os.getppid() = ', os.getppid())
    
    p1 = multiprocessing.Process(target = OtherProcess_Start)

    p1.start()

    print(" Parent process waiting for child-process")
    p1.join()

    print("Parent process end")
    
if __name__ == '__main__':
    main()