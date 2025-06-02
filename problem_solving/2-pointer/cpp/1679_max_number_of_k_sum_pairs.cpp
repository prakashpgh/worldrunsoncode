/*'''
https://leetcode.com/problems/max-number-of-k-sum-pairs

Approach I
    using hashtable.. 
        iterate the array
            check if com
            store the elements

Approach II:
    using 2-pointer approach..
        need to sort the array 
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


int max_number_of_k_sum_pairs_2_ptr(vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int l = 0;
    int r = nums.size() - 1;
    int count = 0;
    while(l < r) {
        int sum = nums[l] + nums[r];
        if(sum == k) {
            count++;
            l++;
            r--;
        } else if(sum < k) {
            l++;
        } else {
            r--;
        }
    } 
    return count;
}



int main() {
    std::vector<int> nums = {1,2,3,4};
    int k = 5;
    //#Output: 2
    int result = max_number_of_k_sum_pairs_2_ptr(nums, k);
    std::cout << "result: " << result << std::endl;
    
    nums = {3,1,3,4,3};
    k = 6;
    //#Output: 1
    result = max_number_of_k_sum_pairs_2_ptr(nums, k);
    std::cout << "result: " << result << std::endl;
}
