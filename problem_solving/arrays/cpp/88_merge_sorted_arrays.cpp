/*
https://leetcode.com/problems/merge-sorted-array/
*/
#include<vector>
#include<iostream>
#include "../../utils/utils.h"

void merge_sorted_arrays(std::vector<int>& nums1, const std::vector<int>& nums2, int m, int n) {
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(i >= 0 and j >= 0) {
        if (nums1[i] < nums2[j]) {
            nums1[k]=nums2[j];
            j -= 1;
        } else {
            nums1[k]=nums1[i];
            i -= 1;
        }
        k -= 1;
    }
    while (j >= 0) {
        nums1[k]=nums2[j];
        k -= 1;
        j -= 1;
    }
}


int main() {
    std::vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    std::vector<int> nums2 = {2,5,6};
    int n = 3;
    //Output: [1,2,2,3,5,6]
    merge_sorted_arrays(nums1, nums2, m, n);
    print_vector(nums1);


    nums1 = {1};
    m = 1;
    nums2 = {};
    n = 0;
    merge_sorted_arrays(nums1, nums2, m, n);
    print_vector(nums1);
    //Output: [1]

    nums1 = {0};
    m = 0;
    nums2 = {1};
    n = 1;
    merge_sorted_arrays(nums1, nums2, m, n);
    print_vector(nums1);
    //Output: [1]
}