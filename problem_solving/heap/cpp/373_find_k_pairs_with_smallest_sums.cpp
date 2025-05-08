/*
'''
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

sorted array..
use of heap

take from the arrays... use only i=0 and min(k, n2) 

while the heap is not empty() && k < result size
        pop and add to the result... till the result size < k and heap is not empty
        as you pop from heap.
        index1 = index of the element popped out of heap
        push with index1 + 1 
array => (sum, i+1,j) & (sum,i,j+1) to heap =>  

'''
*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


std::vector<std::vector<int>> k_smallest_pairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    std::vector<std::vector<int>> result;
    return result;
}

int main() {
    std::vector<int> nums1;
    std::vector<int> nums2;
    nums1 = {1,7,11};
    nums2 = {2,4,6};
    int k = 3;
    //#Output: {{1,2},{1,4},{1,6}}
    std::vector<std::vector<int>> result = k_smallest_pairs(nums1, nums2, k);
    print_vector_of_vector(result);

    nums1 = {1,1,2};
    nums2 = {1,2,3};
    k = 2;
    //#Output: {{1,1},{1,1}}
    result = k_smallest_pairs(nums1, nums2, k);
    print_vector_of_vector(result);
}