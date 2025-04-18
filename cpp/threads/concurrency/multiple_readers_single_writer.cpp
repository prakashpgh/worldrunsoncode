/*
Imagine you have an application where you have multiple readers and a single writer. 
You are asked to design a lock which lets multiple readers read at the same time, but only one writer write at a time.
 */



#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
#include <chrono>

class ReadWriteLock {
private:
    std::mutex mtx;                     // Protects shared state
    std::condition_variable readers_cv; // Signals readers when they can proceed
    std::condition_variable writer_cv;  // Signals writer when it can proceed
    int active_readers = 0;             // Count of active readers
    bool writer_waiting = false;        // Flag if a writer is waiting
    bool writer_active = false;         // Flag if a writer is currently active

public:
    // Acquire a read lock
    void lock_read() {
        std::unique_lock<std::mutex> lock(mtx);
        // Wait if a writer is active or waiting (to avoid starving the writer)
        readers_cv.wait(lock, [this] { return !writer_active && !writer_waiting; });
        active_readers++;
    }

    // Release a read lock
    void unlock_read() {
        std::unique_lock<std::mutex> lock(mtx);
        active_readers--;
        if (active_readers == 0) {
            writer_cv.notify_one();  // Wake a waiting writer if no readers remain
        }
    }

    // Acquire a write lock
    void lock_write() {
        std::unique_lock<std::mutex> lock(mtx);
        writer_waiting = true;  // Signal that a writer is waiting
        // Wait until no readers or writer are active
        writer_cv.wait(lock, [this] { return active_readers == 0 && !writer_active; });
        writer_waiting = false;
        writer_active = true;
    }

    // Release a write lock
    void unlock_write() {
        std::unique_lock<std::mutex> lock(mtx);
        writer_active = false;
        // Notify all readers and one writer (if any)
        readers_cv.notify_all();
        writer_cv.notify_one();
    }
};

// Example usage: Shared resource with multiple readers and one writer
class SharedResource {
private:
    int data = 0;
    ReadWriteLock rw_lock;

public:
    void read(int reader_id) {
        rw_lock.lock_read();
        std::cout << "Reader " << reader_id << " reads: " << data << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // Simulate reading
        rw_lock.unlock_read();
    }

    void write(int value) {
        rw_lock.lock_write();
        std::cout << "Writer sets value to " << value << "\n";
        data = value;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // Simulate writing
        rw_lock.unlock_write();
    }
};

void reader_task(SharedResource& resource, int id) {
    for (int i = 0; i < 3; ++i) {
        resource.read(id);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Delay between reads
    }
}

void writer_task(SharedResource& resource) {
    for (int i = 1; i <= 2; ++i) {
        resource.write(i * 100);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));  // Delay between writes
    }
}

int main() {
    SharedResource resource;
    std::vector<std::thread> threads;

    // Start 4 reader threads
    for (int i = 1; i <= 4; ++i) {
        threads.emplace_back(reader_task, std::ref(resource), i);
    }

    // Start 1 writer thread
    threads.emplace_back(writer_task, std::ref(resource));

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Simulation complete.\n";
    return 0;
}