/*
A barber shop consists of a waiting room with n chairs, and a barber chair for giving haircuts.
If there are no customers to be served, the barber goes to sleep.
If a customer enters the barbershop and all chairs are occupied, then the customer leaves the shop.
If the barber is busy, but chairs are available, then the customer sits in one of the free chairs. If the barber is asleep, the customer wakes up the barber.

*/



#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <vector>
#include <random>

class BarberShop {
private:
    const int max_chairs;                // Number of waiting chairs
    std::mutex mtx;                      // Protects shared state
    std::condition_variable barber_cv;   // Signals barber when customers arrive
    std::condition_variable customer_cv; // Signals customers when barber is ready
    std::queue<int> waiting_customers;   // Queue of customer IDs
    bool barber_sleeping = true;         // Barber's state
    bool shop_open = true;               // Controls shutdown

public:
    BarberShop(int n) : max_chairs(n) {}

    // Barber thread function
    void barber() {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            
            // If no customers and shop is open, sleep
            if (waiting_customers.empty() && shop_open) {
                std::cout << "Barber is sleeping...\n";
                barber_sleeping = true;
                barber_cv.wait(lock, [this] { return !waiting_customers.empty() || !shop_open; });
            }
            
            // Check if shop is closing and no customers remain
            if (!shop_open && waiting_customers.empty()) {
                std::cout << "Barber is closing shop.\n";
                return;
            }
            
            // Serve the next customer
            int customer_id = waiting_customers.front();
            waiting_customers.pop();
            barber_sleeping = false;
            std::cout << "Barber is cutting hair for customer " << customer_id << "\n";
            lock.unlock();  // Unlock before haircut (simulated work)
            
            // Simulate haircut
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            
            std::cout << "Barber finished haircut for customer " << customer_id << "\n";
            customer_cv.notify_one();  // Signal waiting customers that a chair is free
        }
    }

    // Customer thread function
    void customer(int id) {
        std::unique_lock<std::mutex> lock(mtx);
        
        // Check if there's space in the waiting room
        if (waiting_customers.size() >= max_chairs) {
            std::cout << "Customer " << id << " leaves: no chairs available.\n";
            return;
        }
        
        // Add customer to waiting queue
        waiting_customers.push(id);
        std::cout << "Customer " << id << " enters and waits (queue size: " 
                  << waiting_customers.size() << ")\n";
        
        // Wake the barber if sleeping
        if (barber_sleeping) {
            std::cout << "Customer " << id << " wakes the barber.\n";
            barber_cv.notify_one();
        }
        
        // Wait for haircut if barber is busy
        customer_cv.wait(lock, [this, id] { 
            return waiting_customers.empty() || waiting_customers.front() == id; 
        });
        
        // Customer is next in line (lock is still held until haircut starts)
    }

    // Close the shop (called by main thread)
    void close_shop() {
        std::unique_lock<std::mutex> lock(mtx);
        shop_open = false;
        barber_cv.notify_one();  // Wake barber to check shutdown condition
    }
};

// Simulate customer arrivals
void simulate_customer_arrivals(BarberShop& shop, int num_customers) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(200, 800);  // Random delay between arrivals

    std::vector<std::thread> customers;
    for (int i = 1; i <= num_customers; ++i) {
        customers.emplace_back(&BarberShop::customer, &shop, i);
        std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen)));
    }

    // Wait for all customers to finish
    for (auto& t : customers) {
        t.join();
    }
}

int main() {
    const int num_chairs = 3;  // Waiting room capacity
    BarberShop shop(num_chairs);

    // Start barber thread
    std::thread barber_thread(&BarberShop::barber, &shop);

    // Simulate 6 customers arriving over time
    simulate_customer_arrivals(shop, 6);

    // Close the shop after customers are done
    std::this_thread::sleep_for(std::chrono::seconds(1));  // Let last customers finish
    shop.close_shop();

    // Wait for barber to finish
    barber_thread.join();

    std::cout << "Simulation complete.\n";
    return 0;
}