/*
https://leetcode.com/problems/design-underground-system/

user, {start_time, t} in map
route, {time, trips} in map
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


class UndergroundSystem {
    private:
    std::unordered_map<int, std::pair<std::string, int>> user_stationtime_map;
    std::unordered_map<std::string, std::pair<double, int>> route_time_map;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        user_stationtime_map[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        std::string route = user_stationtime_map[id].first + "=>" + stationName;
        double time = t - user_stationtime_map[id].second;
        route_time_map[route].first += time;  
        route_time_map[route].second += 1;

        user_stationtime_map.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        std::string route = startStation + "=>" + endStation;
        double average = route_time_map[route].first / route_time_map[route].second;
        return average;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

 int main() {
    UndergroundSystem undergroundSystem;

    // Test cases from the problem description
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Paradise", 17);
    undergroundSystem.checkOut(32, "Leyton", 20);
    undergroundSystem.checkOut(27, "Paradise", 22);

    std::cout << "getAverageTime(\"Leyton\", \"Paradise\") = " << undergroundSystem.getAverageTime("Leyton", "Paradise") << std::endl; // return 13.00000
    std::cout << "getAverageTime(\"Paradise\", \"Leyton\") = " << undergroundSystem.getAverageTime("Paradise", "Leyton") << std::endl; // return 12.00000
    undergroundSystem.checkIn(10, "Leyton", 24);
    std::cout << "getAverageTime(\"Leyton\", \"Paradise\") = " << undergroundSystem.getAverageTime("Leyton", "Paradise") << std::endl; // return 13.00000
    return 0;
    return 0;
 }