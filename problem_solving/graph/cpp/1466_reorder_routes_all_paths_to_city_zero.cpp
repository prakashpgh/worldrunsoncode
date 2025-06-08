/*
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

what we need to find out the routes that need flipping when all the nodes want to go to 0.

1) create the graph from connections.  add a flag for true, and false for artifical route
        we add artifiical only when 0 => a exists.  lets say 0=>1 exists, we add 0,1 as True, and 1,0 as False
        the purpose is to visit all nodes.  these will not be used when traversing from nodes to 0.
        Note we are travelling away from 0.  so whereve we hit the roads with True, we need to increase the flips

2) start from 0, and do a dfs using visited.  whereeve it travels via original, mark it as flipped
#tricky
*/

#include<iostream>
#include<tuple>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
using namespace std;


class Solve {
    int reorders = 0;
    std::set<int> visited;
    std::unordered_map<int, std::vector<std::pair<int, int>>> routes;
    int flips = 0;

    void dfs(int src) {
        auto neighbors = routes[src];
        visited.insert(src);
        for(auto nei : neighbors) {
            if(visited.find(nei.first) != visited.end()) {
                continue;
            }
            
            if(nei.second) {
                flips++;
            }
            dfs(nei.first);
        }
    }

    public:
    int reorder_routes_all_paths_to_city_zero(std::vector<std::vector<int>> connections) {
        //create the adj. list.
        visited.clear();    
        routes.clear();
        flips = 0;
        for(auto connect : connections ) {
            routes[connect[0]].push_back({connect[1], true});
            routes[connect[1]].push_back({connect[0], false});//added...virtual route
        }
        dfs(0);
        return flips;
    }
    
};



int main() {
    int n = 6;
    std::vector<std::vector<int>> connections = { {0,1} , {1,3}, {2,3}, {4,0}, {4,5} };
    //#Output: 3
    Solve s;
    int result = s.reorder_routes_all_paths_to_city_zero(connections);
    std::cout << "result=" << result << std::endl;
    
    n = 5;
    connections = {{1,0},{1,2},{3,2},{3,4}};
    //#Output: 2
    result = s.reorder_routes_all_paths_to_city_zero(connections);
    std::cout << "result=" << result << std::endl;
    
    
    n = 3;
    connections = {{1,0},{2,0}};
    //#Output: 0;
    result = s.reorder_routes_all_paths_to_city_zero(connections);
    std::cout << "result=" << result << std::endl;
    
    return 0;
}

