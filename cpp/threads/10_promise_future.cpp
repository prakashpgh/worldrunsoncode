/*
Promise 
create a std::promise object
get the std::future out of it
std::move the promise std::thread constructor & in the thread function 1st parameter
    In thread func, set the return value in the promise.set_value
future.get() => get value of the promise <= blocking call

good for one-off synchronous result
*/

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <future>

void thread_func(std::promise<int> promise, int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    try {
        if (a < 0 || b < 0 ) {
            throw std::runtime_error("negative numbers not allowed");
        }
        promise.set_value(a+b);
    } catch(...) {
        promise.set_exception(std::current_exception());
    }
}



void promise_demo() {
    //create a promise and get its future
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    
    //move the promise to the thread
    std::thread t(thread_func, std::move(prom), 5, 10);
    std::cout << "waiting on result " << std::endl;
    //get result from future
    int result = fut.get();
    std::cout << "result " << result << std::endl;
    t.join();

    //exception case
    std::promise<int> prom2;
    std::future<int> fut2 = prom2.get_future();
    std::thread t2(thread_func, std::move(prom2), -5, -10);
    std::cout << "waiting on result " << std::endl;

    try {
        //exception
        result = fut2.get();
        std::cout << "result " << result << std::endl;
    } catch(const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    
    t2.join();

}


int main() {
    promise_demo();

}