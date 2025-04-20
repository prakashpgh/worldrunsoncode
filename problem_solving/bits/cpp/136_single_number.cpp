/*
https://leetcode.com/problems/single-number

xor ^ of a number with itself = 0
*/
#include<vector>
#include<iostream>

int single_number(const std::vector<int>& nums) {
    int result = 0;
    for (int n : nums) {
        result ^= n;
    }
    return result;
}



int main() {
    std::vector<int> nums = {2,2,1};
    int result = single_number(nums);
    std::cout << "result: " << result << std::endl;
}