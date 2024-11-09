#include <iostream>
#include <thread>
#include <vector>

void test(int i)
{
    std::cout << "hello from test..." << std::this_thread::get_id() << " args: " << i << std::endl;
}

int main()
{
    std::thread thread(&test, 10);
    std::cout << "before detach..." << std::endl;
    thread.detach();
    std::cout << "after detach..." << std::endl;
}
