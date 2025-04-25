'''
#https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#find_minimum_in_rotated_sorted_array.py

#this is modified binary search problem.
    first checkif there is no rotation
    get the midpoint in the usual way.
        this is ascending array, rotated... we need to find the smallest numbe
        if n[m] > n[m+1]    => m+1 is the point  
            if n[m-1] > n[m]    => m is the point
            if n[m] > n[l]  => the inflection point is to the right of m, l = m+1
            else
            r = m  

#time O(log N)
#space O(1)
'''


#include<vector>
#include<iostream>


int find_min_rotated_sorted_vector(const std::vector<int>& nums) {
    int l = 0;
    int r = nums.size()-1;
    while(l < r) {
        int m = l + (r-l)/2;
        if(nums[m] > nums[r]) {
            l = m+1;
        } else {
            r = m;
        }
    }
    return nums[l];
}


int main() {
    std::vector<int> nums = {11,12,13,14,15,8,9,10};
    std::cout << "find min element in the rotated sorted array:" << std::endl;
    int result = find_min_rotated_sorted_vector(nums);
    std::cout << result << std::endl;
}