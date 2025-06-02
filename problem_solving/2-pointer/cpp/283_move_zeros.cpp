/*
'''
https://leetcode.com/problems/move-zeroes/description/

for loop for r...
keep a pointer to track the non-zero..

#check
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


void move_zeros(std::vector<int>& nums) {
    int w = 0;
    for (int r = 0; r < nums.size(); ++r) {
        if(nums[r] != 0) {
            nums[w] = nums[r];
            w++;
        }
    }
    for (int i = w; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}



void move_zeros_2(std::vector<int>& nums) {
    int w = 0;
    for (int r = 0; r < nums.size(); ++r) {
        if(nums[r] != 0) {
            nums[w] = nums[r];
            w++;
        }
    }
    for (int i = w; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}


int main() {
    std::vector<int> nums = {1,1,0,3,12};
    move_zeros(nums);
    print_vector(nums);

    nums = {0,1,0,3,12};
    //#Output: [1,3,12,0,0]
    move_zeros(nums);
    print_vector(nums);

    nums = {0};
    move_zeros(nums);
    //#Output: [0]
    print_vector(nums);
}