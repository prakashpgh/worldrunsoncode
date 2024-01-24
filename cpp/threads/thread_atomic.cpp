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

    for (int i = 0; i < 1000; ++i)
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

int main()
{
    for (int i = 0; i < 100; ++i)
    {
        trial();
    }
}
