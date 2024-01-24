#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

int shared_resource = 0;
std::mutex myMutex;

void thread_func()
{
    myMutex.lock();
    shared_resource++;
    myMutex.unlock();
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
