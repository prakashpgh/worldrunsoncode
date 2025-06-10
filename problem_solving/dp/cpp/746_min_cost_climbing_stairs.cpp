/*
'''
https://leetcode.com/problems/min-cost-climbing-stairs/
t: O(N)
s: O(1)

cost of coming to ith floor = min (cost of coming to i-1 + num[i-1],  cost of coming to ith + num[i])
note that the cost 0th and cost 1st = 0 since you can take 1 or 2 steps
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
#include<math.h>


int min_cost_climbing_stairs(std::vector<int> nums)  {
    int len = nums.size();
    if(len < 2) {
        //can start from 0 or 1
        return 0;
    }
    if(len == 2) {
        return std::min(nums[0], nums[1]);
    }
    int cost_i_minus_one = 0;
    int cost_i_minus_two = 0;
    int cost_i = 0;
    for(int i = 2; i < len+1; ++i) {
        cost_i = std::min(cost_i_minus_one + nums[i-1], cost_i_minus_two + nums[i-2]);
        cost_i_minus_two = cost_i_minus_one;
        cost_i_minus_one = cost_i;
    }
    return cost_i;
}



int main() {
    std::vector<int>  cost = {10,15,20};
    //#Output: 15
    int result = min_cost_climbing_stairs(cost);
    std::cout << "result: " << result << std::endl;
    
    
    cost = {1,100,1,1,1,100,1,1,100,1};
    //#Output: 6
    result = min_cost_climbing_stairs(cost);
    std::cout << "result: " << result << std::endl;
    
}
