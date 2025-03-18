/*
https://leetcode.com/problems/print-in-order/description/

unique_lock
cv.wait..
.... stuff
cv.notify

*/
#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <thread>

void printFirst() {
    printf("first");
}

void printSecond() {
    printf("second");
}

void printThird() {
    printf("third");
}

class Foo {
    private:
    int turn = 0;
    std::mutex m;
    std::condition_variable cv;
public:
    Foo() : turn(0) {
        
    }

    void first(std::function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn = 1;
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(m);
        // printSecond() outputs "second". Do not change or remove this line.
        cv.wait(lock, [this] {return turn == 1;});
        printSecond();
        turn = 2;
        cv.notify_all();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(m);
        // printThird() outputs "third". Do not change or remove this line.
        cv.wait(lock, [this] {return turn == 2;});
        
        printThird();
    }
};


int main() {
    int i = 0;
    while (i < 10) {
    Foo foo;
        std::thread t3([&foo]() {foo.third(printThird);});
        std::thread t2([&foo]() {foo.second(printSecond);});
        std::thread t1([&foo]() {foo.first(printFirst);});
        t1.join();
        t2.join();
        t3.join();
        i += 1;
        std::cout << std::endl;
    };
    
    return 0;
}


