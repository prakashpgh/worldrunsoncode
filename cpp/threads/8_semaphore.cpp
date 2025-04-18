/*
Semaphore
    allows one or more threads to access critical section
binary semaphore: mutex

    void wait() {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this] () { return _count > 0;});
        _count--;
    }
Only one thread can hold the lock on the mutex at any given time.

Crucially, multiple threads can acquire the mutex, check the condition, and then call cv.wait() if the condition is false.

lets say T1 acquires the lock, now cv releases the mutex & checks the condition.  
If the condition is fulfilled, then 

When a thread calls cv.wait(), it:
Atomically releases the lock on the mutex.
Suspends the thread's execution.
Waits for a notification from cv.notify_one() or cv.notify_all().
When a notification is received, the thread reacquires the lock on the mutex.
Checks the condition again.
If the condition is true, the thread continues; otherwise, it releases the lock and waits again.

mutex 
    lock ~ wait
    unlock ~ signal

    there is no semaphore class as such in C++, its a concept
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>



class Semaphore {
private:
    std::mutex m;
    std::condition_variable cv;
    int _count;

public:
    Semaphore(int count) : _count(count){
    }

    //equivalent to mutex lock
    void wait() {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this] () { return _count > 0;});
        _count--;
    }

    //mutex unlock
    void signal() {
        std::unique_lock<std::mutex> lock(m);
        _count++;
        cv.notify_one();
    }
};

Semaphore sem(2);

void thread_func(int t_id, int i) {
    sem.wait();

    std::cout << "threadid: "  << t_id << " val:" << i << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    sem.signal();
} 


int main() {
    std::thread t1(thread_func, 1, 11);
    std::thread t2(thread_func, 2, 12);
    std::thread t3(thread_func, 3, 13);
    std::thread t4(thread_func, 4, 14);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}