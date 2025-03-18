/*
https://leetcode.com/problems/building-h2o/description/
*/

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>

void releaseH() {printf("H");}
void releaseO() {printf("O");}


class H2O {
private:
    std::mutex m;
    std::condition_variable cv;
    int h;
    int o;

public:
    H2O(): h(0), o(0) {
        
    }

    void check_n_reset() {
        if (o == 1 && h == 2) {
            o = 0;
            h = 0;
        }
    }

    void hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this] { return h < 2;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h += 1;
        check_n_reset();
        cv.notify_all();
    }

    void oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this] { return o < 1;});
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        o += 1;
        check_n_reset();
        cv.notify_all();
    }
};



int main() {
    H2O h2o;
    std::string s = "HHOHHO";
    std::vector<std::thread> threads;
    for (char c : s) {
        if (c == 'H') {
            threads.emplace_back(([&h2o] () {h2o.hydrogen(releaseH);}));
        } else if (c == 'O') {
            threads.emplace_back(([&h2o] () {h2o.oxygen(releaseO);}));
        }
    }
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}