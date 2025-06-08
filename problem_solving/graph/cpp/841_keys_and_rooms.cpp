/*
https://leetcode.com/problems/keys-and-rooms/description/?envType=study-plan-v2&envId=leetcode-75
841_keys_and_rooms.py

create the graph from the links
use bfs
check the len of visited = len of input array

*/

#include<iostream>
#include<tuple>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
using namespace std;


class Solve {
    private:
    std::set<int> visited;
    bool dfs(std::vector<std::vector<int>> rooms, int src) {
        visited.insert(src);
        if(visited.size() == rooms.size()) {
            return true;
        }
        auto neighbors = rooms[src];
        for(auto nei : neighbors) {
            if(visited.find(nei) == visited.end()) {
                auto ret = dfs(rooms, nei);
                if(ret) {
                    return true;
                }
            }
        }
        return false;
    }
    
    public:
    bool keys_and_rooms(std::vector<std::vector<int>> rooms) {
        visited.clear();
        return dfs(rooms, 0);
    }
    
};



int main() {
    std::vector<std::vector<int>> rooms = {{1},{2},{3},{}};
    //#Output: true
    Solve solve;
    bool result = solve.keys_and_rooms(rooms);
    std::cout << "result: " << result << std::endl;
    
    rooms = {{1,3},{3,0,1},{2},{0}};
    //#Output: false
    result = solve.keys_and_rooms(rooms);
    std::cout << "result: " << result << std::endl;
    
}
