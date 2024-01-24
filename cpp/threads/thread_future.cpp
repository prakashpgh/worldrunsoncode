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
    std::future<int> f = std::async(&square, 12);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int sq = f.get();
    std::cout << "result: " << sq << std::endl;
}
