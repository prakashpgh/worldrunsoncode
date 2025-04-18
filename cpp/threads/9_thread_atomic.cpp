/*
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
