/*
https://leetcode.com/problems/print-foobar-alternately/

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

void printFoo() { printf("foo"); }
void printBar() { printf("bar"); }


class FooBar {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int state = 1;

public:
    FooBar(int n) : state(1) {
        this->n = n;
    }

    void foo(std::function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [this]() {return (state == 1); });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            state = 2;
            cv.notify_all();
        }
    }

    void bar(std::function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [this]() {return (state == 2); });
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            state = 1;
            cv.notify_all();
        }
    }
};


int main() {
    FooBar foobar(10);
    std::thread t1([&foobar]() {foobar.foo(printFoo);});
    std::thread t2([&foobar]() {foobar.bar(printBar);});

    t1.join();
    t2.join();

}