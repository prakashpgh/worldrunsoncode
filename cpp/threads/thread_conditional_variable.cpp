#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>

int shared_resource = 0;
bool notified = false;
std::mutex _mutex;
std::condition_variable _cv;

int main()
{
    std::cout << "main..." << std::endl;
    // reporter
    std::thread reporter([]()
                         { std::unique_lock<std::mutex> lock(_mutex);
                            if(!notified)
                            {
                                std::cout << "reporting waiting ";
                                _cv.wait(lock);
                            }
                            std::cout << "shared_resource: " << shared_resource << std::endl; });

    // worker

    std::thread worker([]()
                       {
                           std::unique_lock<std::mutex> lock(_mutex);
                           shared_resource = 50;
                           std::this_thread::sleep_for(std::chrono::seconds(5));
                           notified = true;
                           _cv.notify_one(); });

    worker.join();
    reporter.join();

    std::cout << "shared_resource: " << shared_resource << std::endl;
}
