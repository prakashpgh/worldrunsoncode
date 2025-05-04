/*
#https://leetcode.com/problems/remove-element/description/
#a-2
'''
O(n)
space: O(1)

iterate from beginning 
Idea is if we encounter target, replace it from end with non-target.
kind of 2-pointer approach
'''
*/
#include<vector>
#include<iostream>
#include "../../utils/utils.h"


int remove_element(std::vector<int>& nums, int val) {
    int k=0;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != val) {
            nums[k] = nums[i];            
            k += 1;
        }
    }
    return k;
}


int main() {
    std::vector<int> nums = {3,2,2,3};
    int val = 3;
    //Output: 2, nums = [2,2,_,_]
    int j = remove_element(nums, val);
    std::cout << "result: " << j << std::endl;

    nums = {0,1,2,2,3,0,4,2};
    val = 2;
    //Output: 5, nums = [0,1,4,0,3,_,_,_]    
    j = remove_element(nums, val);
    std::cout << "result: " << j << std::endl;
}