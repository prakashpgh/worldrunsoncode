/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

iterate.. starting from i=2
k is the write index
if  n[i] != n[i-2], replace n[k] = n[i], k += 1

t: O(n)
s: O(1)
*/
#include<iostream>
#include<vector>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"



int remove_duplicates(std::vector<int>& nums) {
    int l = nums.size();
    if( l <= 2) {
        return l;
    }
    int j = 2;
    for(int i = 2; i < l; ++i) {
        if(nums[i] != nums[j-2]) {
            nums[j] = nums[i];
            j += 1;
        }
    }
    return j;
}



int main() {
    std::vector<int> nums = {1,1,1,2,2,3};
    int k = remove_duplicates(nums);
    std::cout << "result:" << k << std::endl;
}
