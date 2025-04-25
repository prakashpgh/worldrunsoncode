/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150

since its sorted, we can use the 2-ptr approach
*/
#include<vector>
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"



std::vector<int> two_sum_sorted_input(const std::vector<int>& nums, int target)  {
    int l = 0;
    int r = nums.size()-1;
    std::vector<int> results;
    while(l < r) {
        int sum = nums[l] + nums[r];
        if(sum == target) {
            results.push_back(l+1);
            results.push_back(r+1);
            return results;
        } else if ( sum < target ) {
            l += 1;
        } else {
            r -= 1;
        }
    }
    results = {-1,-1};
    return results;
}


int main() {
    std::vector<int> numbers = {2,7,11,15};
    int target = 9;
    //Output: [1,2]
    auto result = two_sum_sorted_input(numbers, target);
    print_vector(result);

    numbers = {2,3,4};
    target = 6;
    //Output: [1,3]
    result = two_sum_sorted_input(numbers, target);
    print_vector(result);

    numbers = {-1,0};
    target = -1;
    //Output: [1,2]
    result = two_sum_sorted_input(numbers, target);
    print_vector(result);

    return 0;
}