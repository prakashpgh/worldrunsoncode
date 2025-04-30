/*
https://leetcode.com/problems/search-insert-position/description/

'''
this is vanilla binary search, with finding the nearest number..
'''
time: O(logN)
space: O(1)
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


int search_index_position(const std::vector<int>& nums, int target) {
    int l = 0;
    int r =  nums.size() -1;
    while (l <= r ) {
        int m = l + (r-l)/2;
        if(nums[m] == target) {
            return m;
        } else if(target > nums[m]) {
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return l;
}


int main() {
    return 0;
}


