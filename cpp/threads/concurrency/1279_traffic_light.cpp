/**
 https://leetcode.com/problems/traffic-light-controlled-intersection/description/
 * 
 cars are the different threads operating on the traffic light code.

here main thing in the carArrived function is the current_road and the road of the car.
lock it...
    1) turn green if your roadId is not same as current road
        cross the road, notify all
 */

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <thread>
#include <vector>


 class TrafficLight {
    private:
    int current_road = 0;
    std::condition_variable cv;
    std::mutex m;
public:
    TrafficLight() : current_road(0) {

    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        std::function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        std::function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        //std::cout << "I Car " << carId << " arrived road " << roadId << std::endl;
        std::unique_lock<std::mutex> lock(m);
        //std::cout << "II Car " << carId << " arrived road " << roadId << std::endl;

        if (current_road != roadId ) {
            turnGreen();
            current_road = roadId;
        }
        crossCar();
        //std::cout << "Car " << carId << " crossed from road " << roadId << std::endl;
    }
};

TrafficLight trafficLight;

auto turnGreen1 = []() { std::cout << "Turn green for road 1" << std::endl; };
auto turnGreen2 = []() { std::cout << "Turn green for road 2" << std::endl; };
auto crossCar = []() {}; // Empty function, just simulates crossing


int main() {
    std::vector<std::thread> cars;
    cars.emplace_back([&trafficLight, turnGreen1, crossCar]() { trafficLight.carArrived(1, 1, 1, turnGreen1, crossCar); });
    cars.emplace_back([&trafficLight, turnGreen2, crossCar]() { trafficLight.carArrived(2, 2, 1, turnGreen2, crossCar); });
    cars.emplace_back([&trafficLight, turnGreen1, crossCar]() { trafficLight.carArrived(3, 1, 2, turnGreen1, crossCar); });
    cars.emplace_back([&trafficLight, turnGreen2, crossCar]() { trafficLight.carArrived(4, 2, 2, turnGreen2, crossCar); });
    cars.emplace_back([&trafficLight, turnGreen1, crossCar]() { trafficLight.carArrived(5, 1, 1, turnGreen1, crossCar); });

    for (auto& car : cars) {
        car.join();
    }
    return 0;
}