/*
join
    the calling thread waits for the thread with join(), if main finishes while the thread function is running
    can join only once. else will crash, use joinable() before join()
    
detach:
    the called thread runs independent of the calling thread.  
    even if the calling thread finishes,the T keeps on running
    but if the process/main thread exits, then your called T finishes
 */

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
