from multiprocessing import Process, Pipe
import os

def sender(conn):
    print("getpid = ", os.getpid())
    print("getppid = ", os.getppid())
    conn.send( 'Hi from sender :-)! ')
    conn.close()

def receiver(conn):
    print("getpid = ", os.getpid())
    print("getppid = ", os.getppid())
    msg = conn.recv()
    print(" Message received is: ", msg)
    conn.close()

if __name__ == '__main__':
    print("getpid = ", os.getpid())
    print("getppid = ", os.getppid())
    parent_conn, child_conn = Pipe()

    p1 = Process(target = sender, args = (parent_conn, ))
    p2 = Process(target = receiver, args = (child_conn, ))

    p1.start(); p2.start(); p1.join(); p2.join()