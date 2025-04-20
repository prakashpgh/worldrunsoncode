/*
https://leetcode.com/problems/single-number-ii/

twos = ones & nums
ones ^= num => removes twos.
threes = ones & twos    
ones &= ~threes => remove threes
twos &= ~threes  => remove threes
*/

#include<vector>
#include<iostream>

int single_number_thrice(const std::vector<int>& nums)  {
    int ones = 0;
    int twos = 0;
    for(int num : nums ) {
        twos |= ones & num;
        ones ^= num;
        int threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}


int main()  {
    std::vector<int> nums = {2,2,3,2};
    int result = single_number_thrice(nums);
    std::cout << "result:" << result << std::endl;
}