#include <iostream>
#include <thread>
#include <vector>

void test(int i)
{
    std::cout << "hello from test..." << std::this_thread::get_id() << std::endl;
    std::cout << "arguments..." << i << std::endl;
}

int main()
{
    // single thread...
    std::thread thread(&test, 10);
    thread.join();
    std::cout << "hello from main..." << std::endl;

    // multiple threads...
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i)
    {
        threads.push_back(std::thread(&test, i));
    }

    for (auto &thread : threads)
    {
        thread.join();
    }
}
