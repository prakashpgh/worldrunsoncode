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
    std::cout << __cplusplus / 100 % 100 << '\n';

    std::jthread jThread(&test, 10);

    jThread.join();
    std::cout << "hello from main..." << std::endl;

    // multiple threads...
    std::vector<std::jthread> threads;

    for (int i = 0; i < 10; ++i)
    {
        threads.push_back(std::jthread(&test, i));
    }
}
