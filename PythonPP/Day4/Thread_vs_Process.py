

print("Concept: CPU-bound → faster with multiprocessing (bypasses GIL).")
print("+- "*25)

import time
from multiprocessing import Pool
from threading import Thread

def compute(n):
    return sum(i*i for i in range(n))


if __name__ == "__main__":
    # Thread version
    start = time.time()
    threads = [Thread(target=compute, args=(10_000_00,)) for _ in range(4)]
    for t in threads: t.start()
    for t in threads: t.join()
    print("Threads Time:", time.time()-start)

    # Process version
    start = time.time()
    with Pool(4) as pool:
        pool.map(compute, [10_000_00]*4)
    print("Processes Time:", time.time()-start)
