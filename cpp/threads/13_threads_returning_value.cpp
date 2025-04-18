/*
1) Using std::promise and std::future

2) Passing a Reference or Pointer to a Shared Variable:

3) std::packaged_task & promise
*/

#include <iostream>
#include <thread>
#include <future>

int threadFunction() {
    // Perform some calculation
    return 42;
}

void using_sref() {
    int result;
    std::mutex mutex;

    std::thread t(threadFunction, std::ref(result), std::ref(mutex));

    t.join();

    std::cout << "Thread result: " << result << std::endl;
}


void using_packaged_task() {
    std::packaged_task<int()> task(threadFunction);
    std::future<int> future = task.get_future();

    std::thread t(std::move(task));

    int result = future.get();
    std::cout << "Thread result: " << result << std::endl;

    t.join();    
}

int main() {
    std::promise<int> promise;
    std::future<int> future = promise.get_future();

    std::thread t([&promise]() {
        try {
            int result = threadFunction();
            promise.set_value(result);
        } catch (...) {
            promise.set_exception(std::current_exception());
        }
    });

    try {
        int result = future.get();
        std::cout << "Thread result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Thread threw an exception: " << e.what() << std::endl;
    }

    t.join();
    return 0;
}