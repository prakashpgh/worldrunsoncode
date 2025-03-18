/*
ThreadPool
    vector<std::thread> which will run worker_thread
    std::queue<std::function<void()>> tasks;
    mutex for the queue
    stop
    condition variable

    constructor to create the vector of threads
    destructor ~ to 
    worker_thread ~ picks from the thread, and executes it
    enqueue ~ add to the queue
*/

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <stdexcept>

class ThreadPool {
    public:
    ThreadPool(int num_threads)  {
        if(num_threads == 0) {
            throw std::invalid_argument("nummber of threads should be greater than zero");
        }
        for (int i = 0; i < num_threads; ++i) {
            workers.emplace_back([this] () {this->worker_thread();});
        }
        std::cout << "threadpool created with " << num_threads << " threads" << std::endl;
    }

    ~ThreadPool() {
       {
            //stop flag
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
       } 
       condition.notify_all();
       for (auto& worker : workers) {
            worker.join();
        }
        std::cout << "threadpool stopped " << std::endl;
    }

    template<typename F, typename... Args>
    void enqueue(F&& f, Args&&... args) {
        auto task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            if(stop) {
                throw std::runtime_error("cannot enqueue task on stopped threadppool");
            }
            tasks.emplace(std::move(task));
        }
        condition.notify_one();
    }    

    void worker_thread() {
        while(true) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(queue_mutex);
                condition.wait(lock, [this] { return stop || !tasks.empty(); });

                if (stop and tasks.empty()) {
                    return;
                }
                task = std::move(tasks.front());
                tasks.pop();
            }
            task();
        };
    }

    private:
    bool stop;
    std::mutex queue_mutex;
    std::vector<std::thread> workers;
    std::condition_variable condition;
    std::queue<std::function<void()>> tasks;
};

void example_task(int id, int duration_ms) {
    std::cout << "Task " << id << " running on thread " 
              << std::this_thread::get_id() << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
    std::cout << "Task " << id << " completed\n";
}


int main() {
    ThreadPool pool(4);  // Create a pool with 4 threads

    // Enqueue some tasks
    for (int i = 0; i < 8; ++i) {
        pool.enqueue(example_task, i, 500);  // Each task sleeps for 500ms
    }

    // Pool is destroyed automatically when main exits
    return 0;
}
