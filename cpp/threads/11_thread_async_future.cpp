/*
async with future
std::async
    launch::async
    launch::deferred=> runs in the calling thread
    launch::async|launch::deferred

std::future f = std::async(flag, thread_funct, )

std::future
    .get

You can do the same thing with directly using std::thread, std::future does have some overhead.  
If performance is an issue, then directly use std::thread

std::async
It abstracts away the details of thread management, allowing the runtime to optimize execution. This might involve creating a new thread, using a thread pool, or even executing the task synchronously (deferred execution).

*/

#include <iostream>
#include <mutex>
#include <vector>
#include <future>
#include <thread>

int square(int i)
{
    int sq = i * i;
    std::cout << "thread_func " << sq << std::endl;
    return sq;
}

int main()
{
    std::future<int> f = std::async(std::launch::async, square, 12);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int sq = f.get();
    std::cout << "result: " << sq << std::endl;
}
