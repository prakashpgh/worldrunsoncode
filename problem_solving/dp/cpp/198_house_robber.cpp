/*
https://leetcode.com/problems/house-robber/


*/

#include<vector>
#include<iostream>



int house_robber(std::vector<int>& dp, 
                const std::vector<int>& nums, int house) {
    if (nums.empty()) {
            return 0;
    }
    if(dp[house] != -1) {
        return dp[house];
    }
    if(house==0) {
        return nums[0];
    }
    if(house==1) {
        return std::max(nums[0], nums[1]);
    }
    dp[house] = std::max( (nums[house] + house_robber(dp, nums, house-2)), 
                        house_robber(dp, nums, house-1));
    return dp[house];
}


int main() {
    std::vector<int> nums = {1,2,3,1};
    std::vector<int> dp(nums.size()+1, -1);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    int result = house_robber(dp, nums, nums.size()-1);
    std::cout << "result:" << result << std::endl;


    nums = {2,7,9,3,1};
    std::vector<int> dp1(nums.size()+1, -1);
    dp1[0] = nums[0];
    dp1[1] = std::max(nums[0], nums[1]);
    result = house_robber(dp1, nums, nums.size()-1);
    std::cout << "result:" << result << std::endl;

    return 0;
}