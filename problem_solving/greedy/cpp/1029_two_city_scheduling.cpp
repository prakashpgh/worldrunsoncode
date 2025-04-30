/*
https://leetcode.com/problems/two-city-scheduling/
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>
#include<algorithm>
using namespace std;

int two_city_minimum_cost(std::vector<vector<int>>& costs)  {
    vector<std::pair<int, int>> diffs;
    int len = costs.size();
    for(int i = 0; i < len; ++i) {
        diffs.push_back({costs[i][0] - costs[i][1], i} );
    }
    //print_vector_of_pairs(diffs);
    std::sort(diffs.begin(), diffs.end());
    //print_vector_of_pairs(diffs);
    int total_cost = 0;
    int n = costs.size() / 2;
    //to palce A
    for(int i = 0; i < n; ++i) {
        total_cost += costs[diffs[i].second][0];
    }
    //to place B
    for(int i = n; i < 2*n; ++i) {
        total_cost += costs[diffs[i].second][1];
    }
    return total_cost;
}


int main() {
    std::vector<std::vector<int>> costs;
    costs = {{10,20},{30,200},{400,50},{30,20}};
    int result = two_city_minimum_cost(costs);
    std::cout << "result: " << result << std::endl;
}