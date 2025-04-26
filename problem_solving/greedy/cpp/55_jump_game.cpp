/*
#jump game 1
#https://leetcode.com/problems/jump-game/description/

greedy approach:
max_reach
iterate from begin
{
    update max_reach to (i + num[i])
}
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


bool jump_game(const std::vector<int>& nums) {
    int max_reach_index = 0;
    int len = nums.size();
    for (int i = 0; i < len; ++len) {
        
    }
    return true;
}


int main() {
    std::vector<int> nums = {2,3,1,1,4};
    //Output: true

    nums = {3,2,1,0,4};
    //Output: false
    return 0;
}


