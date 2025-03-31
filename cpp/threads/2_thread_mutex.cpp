/*
Mutex
Analogy:
    key for bathroom in a cafeteria.
    only 1 person can get the key and enter the bathroom
    bathroom = critical section
    key = mutex
    taking of key => lock
    return key => unlock
    customers => threads

Other analogy: libarary book
    book => shared resource
    checkout process => mutex
    readers => threads
----------------------------------
Multiple threads issues.
    race conditions:  data corruption due to many threads acting on the same data

    dead locks: 

Mutex:
    to avoid race conditions..
    lock()
        CRITICAL SECTION.
    unlock()


    try_lock => non blocking, will return if cannot lock.

====
try_lock as api.
try_lock(m1, m2...)
    lock all the lockable objects

=====
recursive_mutex
    similar to std::mutex with additonal functionalty for recursive locking by the same thread
    it allows the same thread to lock the mutex again and again.. ... 
    this can be useful in case of recurive functions or loops

======
timed_mutex
    similar to std::mutex
    is blocked till timeout_time or the lock is acquired
    try_lock_for

===
recursive_mutex
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

int shared_resource = 0;
std::mutex myMutex;

void thread_func_with_mutex_lock()
{
    myMutex.lock();
    for(int i = 0; i < 100; ++i) {
        shared_resource++;
    }
    myMutex.unlock();
}

void thread_func_with_mutex_try_lock()
{
    if (myMutex.try_lock()) {
        for(int i = 0; i < 100; ++i) {
            shared_resource++;
        }
        myMutex.unlock();
    } else {
        std::cout << "thread_func_with_mutex_try_lock  lock failed..." << std::endl;
    }
}

void test_mutex_lock()
{
    // multiple threads...
    std::vector<std::thread> threads;
    for (int i = 0; i < 1000; ++i)
    {
        threads.push_back(std::thread(&thread_func_with_mutex_lock));
    }
    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << "shared_resource: " << shared_resource << std::endl;

    //using try_lock
    shared_resource = 0;
    std::cout << "begin try_lock shared_resource: " << shared_resource << std::endl;
    threads.clear();
    for (int i = 0; i < 1000; ++i)
    {
        threads.push_back(std::thread(&thread_func_with_mutex_try_lock));
    }
    for (auto &thread : threads)
    {
        thread.join();
    }
    std::cout << "try_lock shared_resource: " << shared_resource << std::endl;
}
////////timed_mutex
std::timed_mutex timed_m;
//the thread function, takes 1 sec.. the timed_mutex we try lock for 1 sec.
//so some threads time out
void tf_timed_mutex(int i) {
    if (timed_m.try_lock_for(std::chrono::seconds(1))) {
        shared_resource++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        timed_m.unlock();
    } else {
        std::cout << "tf_timed_mutex timed out " << i << std::endl;
    }
}

void timed_mutex_demo() {
    shared_resource = 0;
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i)
    {
        threads.push_back(std::thread(tf_timed_mutex, i));
    }
    for (auto &thread : threads)
    {
        thread.join();
    }
    shared_resource = 0;
}

////////////recursive mutex
std::recursive_mutex r_mutex;

void tf_recursive_mutex(int i) {
}

void recursive_mutex_demo() {
    
}


int main()
{
    test_mutex_lock();

    timed_mutex_demo();


}
