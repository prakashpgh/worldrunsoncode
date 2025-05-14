/*
https://leetcode.com/problems/house-robber/

bottom up... fill the dp array
time: O(n)
space: O(n)
https://leetcode.com/problems/house-robber/

https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

Idea:
the robber cannot rob the adjacent houses
    so choice is i-1th house OR i-2  && ith
    max(total till i-2  + value of i   Or   value of i-1)

    max( nums[n] + value(n-2), nums[n-1])

Approach I:
    recursive: time: 2^n
                space: n

Approach I:
    recursive with memo:   time: O(n)
            space: O(n)

Approach II:
    iterative:
        time: O(n)
        space: O(1)
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