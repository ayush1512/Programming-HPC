
    

print("Concept: Use multiprocessing.Value, Array, or Manager for shared state.")
print("+- "*25)


from multiprocessing import Process, Value, Lock

def add_100(num, lock):
    for _ in range(100):
        with lock:
            num.value += 1

if __name__ == "__main__":
    number = Value('i', 0)
    lock = Lock()
    processes = [Process(target=add_100, args=(number, lock)) for _ in range(5)]
    for p in processes: p.start()
    for p in processes: p.join()
    print("Shared number (processes):", number.value)
