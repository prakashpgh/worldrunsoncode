/**
 * 
 unique_lock
cv.wait..
.... stuff
cv.notify
https://leetcode.com/problems/print-zero-even-odd/
 */
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>


void print_number(int n) { printf("%d", n); }



class ZeroEvenOdd {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int state = 1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait( lock, [this] {return (state == 1 || state == 3);} );
            printNumber(0);
            state += 1;
            cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [this] {return state == 4;} );
            printNumber(i);
            state = 1;
            
            cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [this] {return state == 2;} );
            printNumber(i);
            state += 1;
            cv.notify_all();
        }
    }
};


int main() {
    int n = 5;
    ZeroEvenOdd zero(n);

    std::thread t1([&zero]() {zero.zero(print_number);});
    std::thread t2([&zero]() {zero.even(print_number);});
    std::thread t3([&zero]() {zero.odd(print_number);});

    t1.join();
    t2.join();
    t3.join();
}