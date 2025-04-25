/*
https://leetcode.com/problems/plus-one/

iterate from end.. till carry = 0
*/

#include<iostream>
#include<vector>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"

std::vector<int> plus_one(std::vector<int>& nums) {
    int carry = 1;
    int N=nums.size();
    for(int i = N-1; i >= 0; --i ) {
        nums[i] += carry;
        carry = nums[i] / 10; 
        nums[i] %= 10;
        if(carry == 0) {
            return nums;
        }
    }
    if(carry > 0) {
        nums.insert(nums.begin(), carry);
    }
    
    return nums;
}

std::vector<int> plus_one_new_number(std::vector<int>& nums) {
    int carry = 1;
    int N=nums.size();
    std::vector<int> result=nums;
    for(int i = N-1; i >= 0; --i ) {
        result[i] += carry;
        carry = result[i] / 10; 
        result[i] %= 10;
        if(carry == 0) {
            return result;
        }
    }
    if(carry > 0) {
        result.insert(nums.begin(), carry);
    }
    
    return result;
}



int main() {
    std::vector<int> input = {1,2,3};
    print_vector(input);
    auto result = plus_one(input);
    print_vector(result);

    input = {1,2,3};
    result = plus_one_new_number(input);
    print_vector(result);
}