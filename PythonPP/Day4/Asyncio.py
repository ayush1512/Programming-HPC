# Task based parallism

import asyncio
import time
import os

async def worker(name):
    print(f"{name} started")
    print(f'os.getpid() = {os.getpid() }')
    print(f'os.getppid() = {os.getppid() }')
    await asyncio.sleep(2) #time.sleep(2)
    print(f"{name} end")

async def main():
    print(f'os.getpid() = {os.getpid() }')
    print(f'os.getppid() = {os.getppid() }')
    print("+- "*25)
    t1 = asyncio.create_task(worker("Task1111"))
    t2 = asyncio.create_task(worker("Task2222"))

    await t1
    await t2

if '__main__' == __name__:
    asyncio.run(main())
    