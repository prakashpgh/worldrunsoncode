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
    int max_reach = 0;
    int len = nums.size();
    if(len < 2) {
        return true;
    }
    for (int i = 0; i < len; ++i) {
        int reach = i + nums[i];
        max_reach = std::max(max_reach, reach) ;
        if(i >= max_reach) {
            return false;
        }
        if(max_reach >= len-1) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> nums = {2,3,1,1,4};
    //Output: true
    auto result = jump_game(nums);
    std::cout << "result: " << result << std::endl;

    nums = {3,2,1,0,4};
    //Output: false
    result = jump_game(nums);
    std::cout << "result: " << result << std::endl;

    return 0;
}


