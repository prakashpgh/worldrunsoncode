/*
Imagine at the end of a political conference, Republicans and Democrats are trying to leave the venue and ordering Uber rides at the same time. To avoid conflicts, each ride can have either all Democrats or Republicans or two Democrats and two Republicans.
All other combinations can result in a fist-fight.
Your task as the Uber developer is to model the ride requestors as threads. Once an acceptable combination of riders is possible, threads are allowed to proceed to ride.
Each thread invokes the method seated() when selected by the system for the next ride. When all the threads are seated, any one of the four threads can invoke the method drive() to inform the driver to start the ride.

Each requestor is a thread.
requestor is either D or r

mutex
condition_variable
waiting_dems
waiting_repubs
rideInprogress

reuest repub => no. of repub ++  => scheduleride(party, lock) => seats the people 


*/


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

class RideScheduler {
private:
    int waitingRepublicans = 0;  // Number of waiting Republican threads
    int waitingDemocrats = 0;    // Number of waiting Democrat threads
    std::mutex mtx;              // Mutex for synchronization
    std::condition_variable cv;  // Condition variable to signal ride readiness
    bool rideInProgress = false; // Flag to prevent overlapping rides

public:
    RideScheduler() {}

    void requestRideRepublican() {
        std::unique_lock<std::mutex> lock(mtx);
        waitingRepublicans++;
        std::cout << "Republican waiting. R: " << waitingRepublicans << ", D: " << waitingDemocrats << "\n";
        scheduleRide("Republican", lock);
    }

    void requestRideDemocrat() {
        std::unique_lock<std::mutex> lock(mtx);
        waitingDemocrats++;
        std::cout << "Democrat waiting. R: " << waitingRepublicans << ", D: " << waitingDemocrats << "\n";
        scheduleRide("Democrat", lock);
    }

private:
    void scheduleRide(const std::string& party, std::unique_lock<std::mutex>& lock) {
        while (true) {
            if (waitingRepublicans >= 4 && !rideInProgress) {
                // All Republicans ride
                waitingRepublicans -= 4;
                rideInProgress = true;
                lock.unlock(); // Unlock before signaling
                seated();
                cv.notify_all(); // Wake up other threads
                if (party == "Republican") {
                    drive();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate ride
                lock.lock();
                rideInProgress = false;
                cv.notify_all(); // Notify others for next ride
                return;
            } else if (waitingDemocrats >= 4 && !rideInProgress) {
                // All Democrats ride
                waitingDemocrats -= 4;
                rideInProgress = true;
                lock.unlock();
                seated();
                cv.notify_all();
                if (party == "Democrat") {
                    drive();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                lock.lock();
                rideInProgress = false;
                cv.notify_all();
                return;
            } else if (waitingRepublicans >= 2 && waitingDemocrats >= 2 && !rideInProgress) {
                // Mixed ride: 2R + 2D
                waitingRepublicans -= 2;
                waitingDemocrats -= 2;
                rideInProgress = true;
                lock.unlock();
                seated();
                cv.notify_all();
                if (party == "Republican" || party == "Democrat") {
                    drive();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                lock.lock();
                rideInProgress = false;
                cv.notify_all();
                return;
            } else {
                // Wait if no valid combination is possible
                cv.wait(lock);
            }
        }
    }

    void seated() {
        std::cout << "Thread " << std::this_thread::get_id() << " is seated\n";
    }

    void drive() {
        std::cout << "Thread " << std::this_thread::get_id() << " signals driver to start the ride\n";
    }
};

// Thread functions
void republicanThread(RideScheduler& scheduler) {
    scheduler.requestRideRepublican();
}

void democratThread(RideScheduler& scheduler) {
    scheduler.requestRideDemocrat();
}

int main() {
    RideScheduler scheduler;
    std::vector<std::thread> threads;

    // Simulate 6 Republicans and 6 Democrats requesting rides
    for (int i = 0; i < 6; i++) {
        threads.emplace_back(republicanThread, std::ref(scheduler));
        threads.emplace_back(democratThread, std::ref(scheduler));
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All rides completed.\n";
    return 0;
}