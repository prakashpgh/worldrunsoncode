/*
https://leetcode.com/problems/longest-increasing-subsequence/
*/

#include<iostream>
#include<vector>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<limits>
#include<map>
#include<unordered_map>


int length_lis_iterative(const std::vector<int>& nums) {
    std::vector<int> result;
    for(auto num : nums) {
        if(result.empty() || result.back() < num) {
            result.push_back(num);
        } else {
            int l = 0;
            int r = result.size()-1;
            while(l < r) {
                int m = l + (r-l)/2;
                if(result[m] < num) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            result[l] = num;
        }
    }
    return result.size();

}




int recur(std::vector<std::vector<int>>& dp, 
            const std::vector<int>& nums, 
            int current, 
            int prev) {
    int N = dp.size();
    if(current >= nums.size()) {
        return 0;
    }

    if(current >= 0 && current < N && prev >=0 && prev < N) {
        if (dp[current][prev] != -1) {
            return dp[current][prev];
        }
    }
    
    //choice
    //current consider
    int consider_path_len = 0;
    if( prev == -1 || nums[current] > nums[prev]) {
        consider_path_len = 1 + recur( dp, nums, current+1, current);
    }
    //currrent - ignore..
    int ignore_path_len = recur( dp,nums, current+1, prev);
    int total_len = std::max(consider_path_len, ignore_path_len);
    if(current >= 0 && current < N && prev >=0 && prev < N) {
        dp[current][prev] = total_len;
    }
    return total_len;
}


int length_lis(const std::vector<int>& nums) {
    int N = nums.size();
    
    std::vector<std::vector<int>> dp(N+1, std::vector<int>(N+1, -1));
    //print_vector_of_vector(dp);

    int result = recur(dp, nums, 0, -1);
    
    //std::cout << "result: " << result << std::endl;
    return result;
}


int main()  {
    std::vector<int> nums = {10,9,2,5,3,7,101,18};
    int result = length_lis(nums);
    std::cout << "result: " << result << std::endl;
    result = length_lis_iterative(nums);
    std::cout << "result-iterative: " << result << std::endl;
    


    nums = {0,1,0,3,2,3};
    //Output: 4
    result = length_lis(nums);
    std::cout << "result: " << result << std::endl;
    result = length_lis_iterative(nums);
    std::cout << "result-iterative: " << result << std::endl;


    nums = {7,7,7,7,7,7,7};
    //Output: 1
    result = length_lis(nums);
    std::cout << "result: " << result << std::endl;
    result = length_lis_iterative(nums);
    std::cout << "result-iterative: " << result << std::endl;
 }
