/*
use cases:
process v thread

thread 
    light weight process
    process => dedicated and isolated memory, resources like I/O and execution context, high overhead for starting new process
    thread => light weight execution unit within process, shares the process memory space with other threads, lower overhead in starting new thread

use cases:
    spell checker, intelli-sense, browser multiple tabs
    performance - trading processing, 
    things that can be done in parallel



creation of thead
    1) using function
        passing parameters by reference std::ref or std::cref,
            but be mindful of thread safety when using std::ref

    2) using callable class

    3) using lambda

    4) class instance method or the static method

    5) multiple threads can be launched using std::vector<std::thread>
---------------------------------------------

join() 
    blocks the calling thread till the thread on which join is called is finished.
    need to call join, else std::terminate is called

joinable() => to check if a thread is joinable.

detach() => 
        detached thread outlives the thread that started it, but does not outlive the process, 
        i.e if the main thread started this detached thread, detached thread will die once main thread is finished
        

*/

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void test(int i)
{
    //std::cout << "hello from test..." << std::this_thread::get_id() << std::endl;
    //std::cout << "arguments..." << i << std::endl;
}

class Callable {
    public:
    void operator()() {
        std::cout << "hello from Callable" << std::this_thread::get_id() << std::endl;
    }
};

class Test {
    public: 
    void instance_func(int x) {
        std::cout << "Test::instance_func" << std::endl; 
    }

    static void static_func(int x) {
        std::cout << "Test::static_func" << std::endl; 
    }
};

//simple use case for illustrative purpose.  find sum of 
typedef unsigned long long ull;
enum ODD_EVEN {
    EVEN=0,
    ODD=1
};

ull sum(ull start, ull end, ODD_EVEN odd_even) {
    ull sum = 0;
    for (int i = start; i < end; ++i) {
        if ((i & 1) == odd_even) {
            sum += i;
        }
    }
    return sum;
}




int main()
{
    //I single thread...
    //A =>function
    std::thread thread(test, 10);

    //join is needed for the main functio to wait.
    thread.join();
    std::cout << "hello from main..." << std::endl;

    //B=>callable class
    Callable c;
    std::thread t2(c);
    t2.join();


    //C=> lambda
    std::thread t_lambda([]() { std::cout << "hello from lambda " << std::endl; } );
    if (t_lambda.joinable()) {
        t_lambda.join();
    }

    //D:using class 
    Test t;
    //instance method
    std::thread t_instance_func(&Test::instance_func, &t, 5);
    //static method
    std::thread t_static_func(&Test::static_func, 5);
    t_static_func.join();
    t_instance_func.join();

    //D=> creating multiple threads...
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i)
    {
        threads.emplace_back(&test, i);
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    //E=> detach
    std::thread thread_detach([] () { std::this_thread::sleep_for(std::chrono::seconds(20));  
                                    std::cout << "detach thred ended " << std::endl; });
    thread_detach.detach();

    
    //F: long process => divy into to 2 threads
    using namespace std::chrono;    
    ull start = 0;
    ull end = 1800000000;

    auto start_time = std::chrono::high_resolution_clock::now();
    ull sum_even = sum(start, end, ODD_EVEN::EVEN);
    std::cout << "even: " << sum_even << std::endl;

    ull sum_odd = sum(start, end, ODD_EVEN::ODD);
    std::cout << "odd: " << sum_odd << std::endl;
    auto end_time = std::chrono::high_resolution_clock::now();    
    auto duration = duration_cast<std::chrono::seconds>(end_time-start_time);
    std::cout << "seconds: " << duration.count() << std::endl;

    //lets do with threading...
    start_time = std::chrono::high_resolution_clock::now();
    std::thread thread_even(sum, start, end, ODD_EVEN::EVEN);    
    std::thread thread_odd(sum, start, end, ODD_EVEN::ODD);
    thread_even.join();
    thread_odd.join();
    end_time = std::chrono::high_resolution_clock::now();    
    duration = duration_cast<std::chrono::seconds>(end_time-start_time);
    std::cout << "threading seconds: " << duration.count() << std::endl;

    std::cout << "main thread ended" << std::endl;
    return 0;
}
