/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/
#include<vector>
#include<iostream>
#include "../../utils/utils.h"

int remove_duplicates_sorted_array(std::vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    int k = 1;
    int i = 1;
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] != nums[i-1]) {
            nums[k] = nums[i];
            k += 1;
        }
    }
    print_vector(nums);
    return k;
}


int main()  {
    std::vector<int> nums = {1,1,2};
    int ret = remove_duplicates_sorted_array(nums);
    std::cout << "result: " << ret << std::endl;
    //Output: 2, nums = [1,2,_]

    nums = {0,0,1,1,1,2,2,3,3,4};
    //Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
    ret = remove_duplicates_sorted_array(nums);
    std::cout << "result: " << ret << std::endl;

    return 0;
}