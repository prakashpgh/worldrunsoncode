/*
Atomic operations allow for lock-free, thread-safe manipulation of shared data.
atomics:  std::atomic
    load
    store

    Using atomics make sure that the other threads dont see patial updates in the int, 

Memory model orders
    memory_order_seq_cst
    memory_order_acquire
    memory_order_release
    memory_order_relaxed

    Atomic operations are typically implemented using hardware-level instructions, which are very efficient
    much faster than mutex

    std::atomic is for simple, fast atomic operations.
    std::mutex is for protecting complex critical sections.
-----------------------------
at the heart of std::atomic lies the support for atomic instructions provided by the cpu.
read-modify-write

cas compare and swap

======================
Memory barriers
Memory barriers (or fences) are instructions that enforce ordering constraints on memory operations. They ensure that:

Loads and stores are not reordered across the barrier.
Operations performed before the barrier become visible to other threads before operations performed after the barrier.
std::atomic operations implicitly involve appropriate memory barriers based on the specified std::memory_order. Different memory orders (e.g., std::memory_order_relaxed, std::memory_order_acquire, std::memory_order_release, std::memory_order_acq_rel, std::memory_order_seq_cst) 1  dictate the strength of the memory ordering guarantees.   

Memory barriers (or fences) are instructions that enforce ordering constraints on memory operations. They ensure that:

Loads and stores are not reordered across the barrier.
Operations performed before the barrier become visible to other threads before operations performed after the barrier.

std::atomic operations implicitly involve appropriate memory barriers based on the specified 
std::memory_order. Different memory orders (e.g., std::memory_order_relaxed, std::memory_order_acquire, std::memory_order_release, std::memory_order_acq_rel, 
std::memory_order_seq_cst) 1  dictate the strength of the memory ordering guarantees.   

std::memory_order_relaxed: Offers the weakest guarantees. Only atomicity is guaranteed, but no ordering constraints with respect to other memory operations in the same or other threads. It might directly map to a simple atomic instruction without strong memory barriers.

std::memory_order_acquire: An acquire operation prevents memory reads (loads) that appear after it in the program order from being reordered before it. Typically used when acquiring a lock or reading data protected by a lock. It often involves a memory barrier that prevents subsequent loads from moving before the atomic load.

std::memory_order_release: A release operation prevents memory writes (stores) that appear before it in the program order from being reordered after it. Typically used when releasing a lock or writing data that will be read by another thread that performs an acquire operation. It often involves a memory barrier that prevents preceding stores from moving after the atomic store.

std::memory_order_acq_rel: Combines the guarantees of both acquire and release ordering. Typically used for atomic read-modify-write operations like incrementing a counter that also acts as a form of signaling.

std::memory_order_seq_cst (Sequentially Consistent): Provides the strongest memory ordering guarantees. All threads observe a total ordering of sequentially consistent operations. This is the default memory order if none is explicitly specified. It typically involves the most expensive memory barriers to ensure global ordering.

Compiler Instrinsics:
Compilers don't directly emit assembly instructions for std::atomic operations. Instead, they recognize these high-level constructs and translate them into the appropriate platform-specific atomic instructions and memory barrier instructions (often using compiler intrinsics). Intrinsics are special functions that provide low-level access to hardware capabilities.




*/

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>


std::atomic<int> shared_resource = 0;

void thread_func()
{
    shared_resource++;
}

void trial()
{
    // multiple threads...
    std::vector<std::thread> threads;

    for (int i = 0; i < 10000; ++i)
    {
        threads.push_back(std::thread(&thread_func));
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << "shared_resource: " << shared_resource << std::endl;
    shared_resource = 0;
}


/*
4 threads keep writing to 4 different slots of an array.
Main thread reads from this array, and updates a UI accordingly.
	?? => there should not be any synchronization between the writer threads as they are writing to different memory locations
	Should there be synchronization between the writer and reader threads

    no synchronization needed between the writers.
    std::array<std::atomic<int>, 4> data = {0,0,0,0} 
        data[slot].store(id * 100 + i, std::memory_order_relaxed);

        int i = data[slot].load(std::memory_order_relaxed);
 */
std::array<std::atomic<int>, 4> data = {0,0,0,0};

void writer(int slot, int id) {
    for(int i = 0; i < 1000; ++i) {
        data[slot].store(id * 100 + i, std::memory_order_relaxed);
        std::this_thread::sleep_for(std::chrono::microseconds(5000));
    }
}

void reader() {
    for(int i = 0; i < 1000; ++i) {
        int v0 = data[0].load(std::memory_order_relaxed);
        int v1 = data[1].load(std::memory_order_relaxed);
        int v2 = data[2].load(std::memory_order_relaxed);
        int v3 = data[3].load(std::memory_order_relaxed);
        std::cout << "ui update: " << v0 << "-" << v1 << "-" << v2 << "-" << v3 << "-" << std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(400));
    }
}

void atomics_example() {
    std::thread tw0(writer, 0, 100);
    std::thread tw1(writer, 1, 200);
    std::thread tw2(writer, 2, 300);
    std::thread tw3(writer, 3, 400);

    std::thread read(reader);

    tw0.join();
    tw1.join();
    tw2.join();
    tw3.join();
    read.join();
}


int main()
{
    trial();

    atomics_example();
}
