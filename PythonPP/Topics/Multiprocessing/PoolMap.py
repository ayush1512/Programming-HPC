import multiprocessing
import time

def square(number):
    """A function to square a number, simulating some work."""
    # time.sleep(10) # Simulate some processing time
    return number * number

if __name__ == "__main__":
    numbers = range(100)

    start1 = time.time()
    for i in numbers:
        square(i)
    end1 = time.time()
    print(f"Time taken normally = {end1-start1}")

    start = time.time()
    # Create a Pool of worker processes
    with multiprocessing.Pool() as pool:
        # Apply the 'square' function to each number in parallel
        results = pool.map(square, numbers)
    end = time.time()
    print(f"Time taken using multiprocessing = {end-start}")

    print(f"Original numbers: {list(numbers)}")
    print(f"Squared results: {results}")
