/*
https://leetcode.com/problems/design-bounded-blocking-queue/

mutex
cv for full 
cv for empty

unique_lock
cv.wait..
.... stuff
cv.notify
*/

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
#include <vector>


class BoundedBlockingQueue {
private:
    int _capacity;
    std::mutex m;
    std::condition_variable cv_not_full;
    std::condition_variable cv_not_empty;
    std::vector<int> q;
public:
    BoundedBlockingQueue(int capacity) : _capacity(capacity) {
        
    }
    
    void enqueue(int element) {
        std::unique_lock<std::mutex> lock(m);
        cv_not_full.wait(lock, [this] {return q.size() < _capacity;});
        q.push_back(element);
        cv_not_empty.notify_all();
    }
    
    int dequeue() {
        std::unique_lock<std::mutex> lock(m);
        cv_not_empty.wait(lock, [this] {return q.size() > 0;});              
        int result = q.front();
        q.erase(q.begin());
        cv_not_full.notify_all();
        return result;
    }
    
    int size() {
        std::unique_lock<std::mutex> lock(m);
        return q.size();
    }
};


int main() {
    BoundedBlockingQueue q(2);

    std::thread producer([&q] () {
        q.enqueue(1);
        std::cout << "en 1 " << std::endl;
        q.enqueue(2);
        std::cout << "en 2 " << std::endl;
        q.enqueue(3);
        std::cout << "en 3 " << std::endl;
    });

    std::thread consumer([&q] () {
        std::cout << "dq: " << q.dequeue() << std::endl;
        std::cout << "dq: " << q.dequeue() << std::endl;
        std::cout << "dq: " << q.dequeue() << std::endl;
    });

    producer.join();
    consumer.join();
}