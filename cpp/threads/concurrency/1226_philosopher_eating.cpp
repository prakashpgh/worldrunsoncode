/**
 * https://leetcode.com/problems/the-dining-philosophers/description/
 
 Imagine you have five philosophers sitting around a roundtable. The philosophers do only two kinds of activities. One: they contemplate, and two: they eat.
However, they have only five forks between themselves to eat their food with. Each philosopher requires both the fork to his left and the fork to his right to eat his food.
Design a solution where each philosopher gets a chance to eat his food without causing a deadlock.


 here the order of picking fork should be different eithe for one or the phils, or even/odd, else will cause deadlock

 use unique lock with defer_lock
 */

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
#include <vector>


// Example usage (for testing):
void pickLeftFork() {
    // std::cout << "Picked left fork" << std::endl;
}

void pickRightFork() {
    // std::cout << "Picked right fork" << std::endl;
}

void eat() {
    // std::cout << "Eating" << std::endl;
}

void putLeftFork() {
    // std::cout << "Put down left fork" << std::endl;
}

void putRightFork() {
    // std::cout << "Put down right fork" << std::endl;
}

 class DiningPhilosophers {
    private:
    mutex mtx[5];

public:
    DiningPhilosophers()  {
        

    }

    void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void()> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        unique_lock<mutex> lck1(mtx[left], defer_lock); // defer_lock: init lck1 without locking mtx
        unique_lock<mutex> lck2(mtx[right], defer_lock);
        
        if(philosopher % 2 == 0){
            lck1.lock(); // do NOT use std::lock(lck1, lck2)
            lck2.lock();
            pickLeftFork(); pickRightFork();
        }
		else{
            lck2.lock();
            lck1.lock();
            pickLeftFork(); pickRightFork();
        }
        eat(); putRightFork(); putLeftFork();
    }
};


int main() {
    DiningPhilosophers philosopher;
    std::vector<std::thread> philosophers;
    for(int i = 0; i < 5; ++i) {
        philosophers.emplace_back([&philosopher, i] () {
            philosopher.wantsToEat( i, pickLeftFork, pickRightFork, eat, putLeftFork, putRightFork);
        });
    }

    for(auto& t : philosophers) {
        t.join();
    }
    return 0;
}