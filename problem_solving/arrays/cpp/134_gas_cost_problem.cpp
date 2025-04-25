/*
https://leetcode.com/problems/gas-station/

net gas = gas - cost
total gas > total cost => possible, else not possible
if gas turns -ve, then all stations till that point are not a good starting point.
*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


int gas_cost_problem(const std::vector<int>& gas, const std::vector<int>& cost) {
    int total_gas = 0;
    int current_gas = 0;
    int station = 0;
    int g = gas.size();

    for(int i = 0; i < g; ++i) {
        int net = gas[i] - cost[i];
        total_gas += net;
        current_gas += net;

        if(current_gas < 0) {
            station = i+1;
            current_gas = 0;
        }
    }
    if(total_gas >= 0) {
        return station;
    } else {
        return -1;
    }
}


int main() {
    std::vector<int> gas = {1,2,3,4,5};
    std::vector<int> cost = {3,4,5,1,2};
    //Output: 3
    int result = gas_cost_problem(gas, cost);
    std::cout << "result: " << result << std::endl;
}