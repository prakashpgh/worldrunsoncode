/*
condition variable

Steps
    unique_lock
    cv.wait => checks condition, if false, release the acquired lock.
        do work
    notifyone/all
---------------------
notify
    notify one or all threads
Scenario:
Thread(s) are waiting on some condition..
Another thread which is running notifies one or all with the cv.

Use cases
Producer consumer problem

*/

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>



int shared_counter = 0;
std::mutex m;
std::condition_variable cv;

/*
the decrement thread gets the mutex... 
the cv waits on the condition and releases the mutex
the increment thread increments and notifies.
the decrement thread gets notified.. checks the coniditon, and proceeds.
*/
int THESHOLD = 20;
bool increment_done = false;

void thread_decrement() {
    
    for(int i = 0; i < 200; ++i) {
        std::unique_lock<std::mutex> lock(m);
        std::cout << "thread_decrement before cv " << shared_counter  << std::endl;
        cv.wait(lock, [] {return (shared_counter > THESHOLD) || increment_done;});
        if (shared_counter > THESHOLD) {
            shared_counter = shared_counter - THESHOLD;
        }
        std::cout << "decrement done " << shared_counter << std::endl;
    }
    std::cout << "thread_decrement end " << shared_counter << std::endl;

}

void thread_increment() {
    
    for(int i = 0; i < 200; i=i+5) {
        std::lock_guard<std::mutex> lock(m);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        shared_counter = shared_counter+5;
        std::cout << "thread_increment done " << shared_counter  << std::endl;
        cv.notify_one();
    }
    increment_done = true;
    cv.notify_one();
}

condition_variable_demo() {
    std::thread t_decrement(thread_decrement);
    std::thread t_increment(thread_increment);

    t_increment.join();
    t_decrement.join();
}




int main()
{
    condition_variable_demo();
}
