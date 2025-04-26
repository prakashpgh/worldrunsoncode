/*
'''
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

https://www.youtube.com/watch?v=4sQL7R5ySUU

find the occurence as normal binary search...
    for equal case,
        index = m
    if left, search left,
    if right search right
        call the function for both left and right search

#meta
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
using namespace std;


int find_first_last_position_sorted_array(const std::vector<int> nums, int target, bool leftside) {
    std::vector<int> result;
    int len = nums.size();
    int l = 0;
    int r = len - 1;
    int index = -1;
    while(l <= r) {
        int m = l + (r-l)/2;
        if(nums[m] < target) {
            l = m + 1;
        } else if (target < nums[m]) {
            r = m - 1;
        } else {
            index = m;
            if(leftside) {
                r = m - 1; 
            } else {
                l = m + 1;
            }
        }

    }
    return index;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int index1 = find_first_last_position_sorted_array( nums, target, true);
    int index2 = find_first_last_position_sorted_array( nums, target, false);
    return {index1, index2};
}



int main() {
    std::vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    //#Output: [3,4]
    auto result = searchRange(nums, target);
    print_vector(result);

    nums = {5,7,7,8,8,10};
    target = 6;
    //#Output: [-1,-1]
    result = searchRange(nums, target);
    print_vector(result);

    nums = {};
    target = 0;
    //#Output: [-1,-1]
    result = searchRange(nums, target);
    print_vector(result);

    return 0;
}

/*
def find_first_last_position_sorted_array(nums: list[int], target: int):

    def search(l:int, r:int, target, left_search: bool):
        l = 0
        r = len(nums) - 1 
        index = -1
        while l <= r:
            m = l + (r-l)//2
            if target > nums[m]:
                l = m + 1
            elif target < nums[m]:
                r = m - 1
            else:
                index = m
                if left_search:
                    r = m -1
                else:
                    l = m + 1
        return index
    
    left = search(0, len(nums)-1, target, True )
    right = search(0, len(nums)-1, target, False )
    return [left, right]
*/