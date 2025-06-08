/*
https://leetcode.com/problems/number-of-provinces/description/

this can be solved by bfs, dfs & disjoint sets.
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
    std::unordered_map<int, std::vector<int>> provinces;

    int dfs(int src)  {
        visited.insert(src);
        auto neighbors = provinces[src];
        for(auto nei : neighbors) {
            if(visited.find(nei) == visited.end()) {
                dfs(nei);
            } 
        }
    }
    
    public:
    int number_of_provinces_dfs(std::vector<std::vector<int>> connections ) {
        visited.clear();
        provinces.clear();
        
        int result = 0;
        //create the adj. list.        
        for(int i = 0; i < connections.size(); ++i) {
            for(int j = 0; j < connections[0].size(); ++j) {
                if(connections[i][j] == 1) {
                    provinces[i].push_back(j);
                }
            }
        }
        
        //dfs into the vector if not already visited.
        for(int i = 0; i < connections.size(); ++i) {
            if(visited.find(i) != visited.end()) {
                continue;
            }
            result++;
            
            dfs(i);
            if(visited.size() == connections.size()) {
                break;
            }
        }
    
        return result;
    }
    
};


int main() {
    std::vector<std::vector<int>> connections = {{1,1,0},{1,1,0},{0,0,1}};
    //#Output: 2
    Solve solve;
    int provinces = solve.number_of_provinces_dfs(connections);
    std::cout << "provinces: " << provinces << std::endl;


    connections = {{1,0,0},{0,1,0},{0,0,1}};
    //    #Output: 3
    provinces = solve.number_of_provinces_dfs(connections);
    std::cout << "provinces: " << provinces << std::endl;
}