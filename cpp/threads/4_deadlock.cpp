/*
deadlock
    T1 acquired M1, waiting on M2.
    T2 acquired M2, waiting on M1

To avoid deadlocks
    lock mutexes in the same order

    Case NO Deadlock
    T1
    lock(M1, M2,M3,M4)
    T2
    lock(M3,M4,M1, M2)


    Case Deadlock
    T1
    lock(M1, M2)
    lock(M3,M4)

    T2
    lock(M3,M4)
    lock(M1, M2)
*/

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex m1;
std::mutex m2;
int shared_resource = 0;
int tries = 10000;

void t1() {
    for(int i = 0; i < tries; ++i) {
        std::cout << "t1 m1: " << std::endl;
        std::lock_guard<std::mutex> l1(m1);   
        std::cout << "t1 m2: " << std::endl;
        std::lock_guard<std::mutex> l2(m2);
        std::cout << "t1 shared resource: " << shared_resource << std::endl;
    }
}

//if true then the mutexes are acquired in the same order, and deadlock does not occur
bool sameorder = false;

void t2() {
    for(int i = 0; i < tries; ++i) {
        if(sameorder) {
            std::cout << "t2 m1: " << std::endl;  
            std::lock_guard<std::mutex> l2(m1);

            std::cout << "t2 m2: " << std::endl;
            std::lock_guard<std::mutex> l1(m2); 
        } else {
            std::cout << "t2 m2: " << std::endl;
            std::lock_guard<std::mutex> l1(m2); 
            std::cout << "t2 m1: " << std::endl;  
            std::lock_guard<std::mutex> l2(m1);
        }
        std::cout << "t2 shared resource: " << shared_resource << std::endl;
    }
}


void deadlock_demo() {
    std::thread th1(t1);
    std::thread th2(t2);

    th1.join();
    th2.join();
}


////////////////////////////////////
//std::lock()

std::mutex m3;
std::mutex m4;
std::mutex m5;
std::mutex m6;


void t3() {
    for(int i = 0; i < tries; ++i) {
        /*  Case A => NO deadlock => A case
        std::lock(m3, m4,m5,m6);   
        m3.unlock();
        m4.unlock();
        m5.unlock();
        m6.unlock();
        */

        /*
        //Case B 
        std::lock(m3, m4);   
        std::lock(m5,m6);   
        m3.unlock();
        m4.unlock();
        m5.unlock();
        m6.unlock();
        */

        std::cout << "t3 shared resource: " << shared_resource << std::endl;
    }
}

void t4() {
    for(int i = 0; i < tries; ++i) {
        /* Case A => No deadlock
        std::lock(m3, m4);   
        std::lock(m5, m6);   
        m3.unlock();
        m4.unlock();
        m5.unlock();
        m6.unlock();
        */

        /*
        //case B deadlock =>change or order
        std::lock(m5,m6);   
        std::lock(m3, m4);   
        m3.unlock();
        m4.unlock();
        m5.unlock();
        m6.unlock();
        */

        std::cout << "t4 shared resource: " << shared_resource << std::endl;
    }
}


void std_lock_demo() {
    std::thread th3(t3);
    std::thread th4(t4);

    th3.join();
    th4.join();    
}


int main() {
    //deadlock_demo();
    
    std::cout << "std_lock_demo ... " << std::endl;
    std_lock_demo();
    std::cout << "main ... " << std::endl;
}




