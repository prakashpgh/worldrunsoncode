/*
explicit word is used to prevent implicit conversion.
*/

#include <mutex>

template <typename Mutex>
class lock_guard {
public:
    explicit lock_guard(Mutex& mutex) : mutex_(mutex) {
        mutex_.lock();
    }

    ~lock_guard() {
        mutex_.unlock();
    }

    // Prevent copy and move operations
    lock_guard(const lock_guard&) = delete;
    lock_guard& operator=(const lock_guard&) = delete;
    lock_guard(lock_guard&&) = delete;
    lock_guard& operator=(lock_guard&&) = delete;

private:
    Mutex& mutex_;
};

// Example usage:
#include <iostream>
#include <thread>
#include <vector>

std::mutex my_mutex;
int shared_data = 0;

void increment_shared_data() {
    lock_guard<std::mutex> lock(my_mutex); // Lock acquired here
    for (int i = 0; i < 100000; ++i) {
        shared_data++;
    } // Lock released when 'lock' goes out of scope
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(increment_shared_data);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Shared data: " << shared_data << std::endl;
    return 0;
}