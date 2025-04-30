/*
Given an array nums of distinct integers that is first strictly decreasing and then strictly increasing, find the index or value of the minimum element using binary search. The array is guaranteed to have at least one element, and the transition point (minimum) exists.

Strictly Decreasing: For indices i < j before the minimum, nums[i] > nums[j].
Strictly Increasing: For indices i < j after the minimum, nums[i] < nums[j].
The array forms a "V" shape, e.g., [5,4,3,2,1,3,4] where 1 is the minimum.

Input: nums = [5,4,3,2,1,3,4]
Output: 1 (value at index 4) or 4 (index of minimum)
Explanation: The array decreases from 5 to 1, then increases from 1 to 4. The minimum is 1 at index 4.

Input: nums = [2,1,3]
Output: 1 (value at index 1) or 1 (index of minimum)
Explanation: Decreases from 2 to 1, increases from 1 to 3.

Input: nums = [3,1]
Output: 1 (value at index 1) or 1 (index of minimum)
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


int find_valley(const std::vector<int>& nums) {
    int len = nums.size();
    if (len == 1) {
        return nums[0];
    }
    if(len == 2) {
        return std::min(nums[0], nums[1]);
    }
    int l = 0;
    int r = len - 1;
    while(l <= r) {
        int m = l + (r-l)/2;

        if(m == 0) {
            if (nums[0] < nums[1]) {
                return 0;
            } else {
                return 1;
            }
        }

        if(m == len-1) {
            if(nums[m] < nums[m-1]) {
                return m;
            } else {
                return m-1;
            }
        }

        //valley case
        if(nums[m] < nums[m+1] && nums[m] < nums[m-1]) {
            return nums[m];
        }
        // If nums[mid] > nums[mid + 1], mid is in decreasing part, minimum is to left
        else if(nums[m] > nums[m+1]) {   //increasing,min is to  
            r = m -1;
        }
        // If nums[mid] > nums[mid - 1], mid is in increasing part, minimum is to right
        else if(nums[m] > nums[m-1]) {   //increasing 
            l = m + 1;
        } 

    }
    return -1;
}


int main() {

    return 0;
}

