/*
https://leetcode.com/problems/median-of-two-sorted-arrays/

https://www.youtube.com/watch?v=q6IEA26hvXc

    idea is run binary search on smaller array, and use that to deduce the median

find m = l + (r-l)//2
        find the smaller of the 2 arrays... lets call it A
            half = len(A1) + len(A2)
            run binary search on this.. find i (m in terms of binary search lingo)
            now since the second array B is sorted.., its mid will be j = half - i -2
            check if the 2 partitions are correct.
                check partitions are correct
                    rightmost_left_A < leftmost_right_B
                    rightmost_left_B < leftmost_right_A
                        If the partitions are correct then we find the median
                            odd: min(a-right, b-right)
                            even: (max(a-left,b-left) + min(aright,bright)       )/2
                        else if A, left > B' right
                            r = i -1
                        else
                            l = i + 1        

            

        median = 
                min(left partitions)
                max(right partitions)


*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


double median_two_sorted_arrays(const std::vector<int>& nums1, const std::vector<int>& nums2)  {
    double median = 0;

    return median;
}


int main() {
    std::vector<int> nums1 = {1,3};
    std::vector<int> nums2 = {2};
    //Output: 2.00000
    double result = median_two_sorted_arrays(nums1, nums2);
    std::cout << "result: " << result << std::endl;

    nums1 = {1,2};
    nums2 = {3,4};
    //Output: 2.50000
    result = median_two_sorted_arrays(nums1, nums2);
    std::cout << "result: " << result << std::endl;
}