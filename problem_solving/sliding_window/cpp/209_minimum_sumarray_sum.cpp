/*
*/

#include<iostream>
#include "../../utils/utils.h"
#include<vector>

int minimum_sumarray_sum(int target, const std::vector<int>& nums) {
    int min_len = INT_MAX;
    int l = 0;
    int curr_sum = 0;
    
    for (int r = 0; r < nums.size(); r++) {
        curr_sum += nums[r];
        while (curr_sum >= target) {
            min_len = std::min(r-l+1, min_len);
            curr_sum -= nums[l];
            l += 1;
        }
    }
    if (min_len == INT_MAX) {
        return 0;
    } else {
        return min_len;
    }
}



int main() {
    int target = 7;
    std::vector<int> nums = {2,3,1,2,4,3};
    //Output: 2
    int result = minimum_sumarray_sum(target, nums);
    std::cout << "result: " << result << std::endl;

    target = 4;
    nums = {1,4,4};
    //Output: 1
    result = minimum_sumarray_sum(target, nums);
    std::cout << "result: " << result << std::endl;

    target = 11;
    nums = {1,1,1,1,1,1,1,1};
    //Output: 0    
    result = minimum_sumarray_sum(target, nums);
    std::cout << "result: " << result << std::endl;
}