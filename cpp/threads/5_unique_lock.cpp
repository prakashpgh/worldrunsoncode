/*
unique_lock

1) strategies: defer_lock, try_to_lock, adopt_lock
2) time constrained attempts
3) recursive locking
4) transfer of lock ownership
5) condition variable
                
*/


#include <mutex>
#include <thread>
#include <iostream>

int shared_data = 0;
std::mutex m;

void thread_func(int thread_id, int incr) {
    std::unique_lock<std::mutex> lock(m);
    for (int i = 0; i < incr; ++i) {
        shared_data++;
    }
    std::cout << "threadid: " << thread_id << " shared_data: " << shared_data << std::endl;
    std::flush(std::cout);
}

void unique_lock_demo() {
    int count = 100000;
    shared_data=0;
    std::thread t1(thread_func, 1, count);

    std::thread t2(thread_func, 2, count);
    std::cout << " shared_data: " << shared_data << std::endl;

    t1.join();
    t2.join();
}



int main() {
    unique_lock_demo();
}