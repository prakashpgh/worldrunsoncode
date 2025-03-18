/**
 * 
 */


 #include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
#include <vector>

void printFizzBuzz() {
    printf("fizzbuzz");
}

void printFizz() {
    printf("fizz");
}

void printBuzz() {
    printf("buzz");
}

void printNumber(int n) {
    printf("%d", n);
}


class FizzBuzz {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int count = 1;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(std::function<void()> printFizz) {
        std::unique_lock<std::mutex> lock(m);
        while (count <= n) {
            if (count % 3 == 0 && count % 5 != 0) {
                printFizz();
                count++;
                cv.notify_all();
            } else {
                cv.wait( lock, [this] { return (count > n || (count % 3 == 0 && count % 5 != 0));});
            }

        }
    }

    // printBuzz() outputs "buzz".
    void buzz(std::function<void()> printBuzz) {
        std::unique_lock<std::mutex> lock(m);
        while (count <= n) {
            if (count % 3 != 0 && count % 5 == 0) {
                printBuzz();
                count++;
                cv.notify_all();
            } else {
                cv.wait( lock, [this] { return (count > n || (count % 3 != 0 && count % 5 == 0));});
            }

        }
    }


    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(std::function<void()> printFizzBuzz) {
        std::unique_lock<std::mutex> lock(m);
        while (count <= n) {
            if (count % 3 == 0 && count % 5 == 0) {
                printFizzBuzz();
                count++;
                cv.notify_all();
            } else {
                cv.wait( lock, [this] { return (count > n || (count % 3 == 0 && count % 5 == 0));});
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(std::function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lock(m);
        while (count <= n) {
            if (count % 3 != 0 && count % 5 != 0) {
                printNumber(count);
                count++;
                cv.notify_all();
            } else {
                cv.wait( lock, [this] { return (count > n || (count % 3 != 0 && count % 5 != 0));});
            }
        }
    }
};


int main() {
    FizzBuzz fizzbuzz(10);

}