/*
producer consumer / bounded buffer problem
producer = thread
consumer = thread
buffer

producer
    mutex lock
    cv_not_full wait
    insert into buffer
    unlock
    notify not_empty

consumer
    mutex lock
    cv_not_empty wait
    get the buffer item
    unlock mutex
    cv not_full notify
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <deque>

std::deque<int> buffer;
std::mutex m;
std::condition_variable cv_not_full;
std::condition_variable cv_not_empty;
int buffer_size = 50;


void producer(int val) {
    while (val) {
        std::unique_lock<std::mutex> lock(m);
        cv_not_full.wait(lock, [] () {return buffer.size() < buffer_size;});
        buffer.push_back(val);
        std::cout << "produced: " << val << std::endl;
        val--;
        lock.unlock();
        cv_not_empty.notify_one();
    };
    std::cout << "producer thread finished " << std::endl;
}


void consumer() {
    while(true) {
        std::unique_lock<std::mutex> lock(m);
        cv_not_empty.wait(lock, [] () {return buffer.size() > 0;});
        int val = buffer.front();
        buffer.pop_front();
        std::cout << "consumed: " << val << std::endl;
        lock.unlock();
        cv_not_full.notify_one();
    };
    std::cout << "consumer thread finished " << std::endl;
}


int main() {
    std::thread th_producer(producer, 10000);
    std::thread th_consumer(consumer);
    th_producer.join();
    th_consumer.join();
}