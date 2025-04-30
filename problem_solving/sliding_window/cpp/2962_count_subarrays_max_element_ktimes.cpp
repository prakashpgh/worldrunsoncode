/*
https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


long long count_subarrays_max_element_k_times(std::vector<int>& nums, int k) {
    int len = nums.size();
    if(len == 0) {
        return 0;
    }
    int max_element = nums[0];

    //find max element
    for(int i = 0; i < len; ++i) {
        max_element = std::max(max_element, nums[i]);
    }
    std::cout << "max: " << max_element << std::endl;
    int l = 0;
    int count_max = 0;
    long long count = 0;
    for(int r = 0; r < len; ++r) {
        if(nums[r] == max_element) {
            count_max += 1;
        }
        while(l <= r && count_max >= k) {
            //count += l + 1;//subarrays 0... l
            if(nums[l] == max_element) {
                count_max -= 1;
            }
            l += 1;
        }
        count += l;
    }
    return count;
}


int main() {
    std::vector<int> nums;
    int k = 2;
    nums = {1,4,2,4,4};
    int result = count_subarrays_max_element_k_times(nums, k);
    std::cout << "result: " << result <<  std::endl;
    //6

    nums = {2,2,2,2};
    k = 2;
    //Output: 7
    result = count_subarrays_max_element_k_times(nums, k);
    std::cout << "result: " << result <<  std::endl;

    return 0;
}