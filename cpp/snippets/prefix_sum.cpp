/*
this concept is used to find the sum of subarrays related problems == target
it can be 1D, 2D or binary tree.
you find the presums

Idea:
you have the cumulative sum in curr_sum & maintain the count in a hash_map
{0,1} sum of zero without any elements
if curr_sum-k is already in hashmap, then there is a subarray with sum = k because curr_sum - (current_sum - k )  = k, so there is a subarray between these 2 indices
so you add the presum[curr_sum - k ] 

#important

nums = [1, 2, 3, -5, 1]
k = 1

similar logic can be applied to binary trees..
*/
/*
https://leetcode.com/problems/subarray-sum-equals-k/description/
t: O(n)
s: O(n)

===============================
The Remainder Property:

The core idea is that if the cumulative sum from index 0 to i and the cumulative sum from index 0 to j have the same remainder when divided by k, then the sum of the subarray from i+1 to j is a multiple of k.
Mathematically:
sum(0, j) % k == remainder
sum(0, i) % k == remainder
Therefore, (sum(0, j) - sum(0, i)) % k == 0
Which means sum(i+1, j) % k == 0'

*/
#include<vector>
#include<iostream>
#include<unordered_map>

int subarray_sum(const std::vector<int>& nums, int k) {
    int count = 0;
    std::unordered_map<int, int> map;
    map[0]=1;
    int sum = 0;
    for(int num : nums) {
        sum += num;
        if(map.find(sum-k) != map.end()) {
            count += map[sum-k];
        }
        map[sum] += 1;
    }
    return count;
}



int main() {
    std::vector<int> nums = {1,1,1};
    int k = 2;
    //Output: 2
    int result = subarray_sum(nums, k);
    std::cout << result << std::endl;

    nums = {1,2,3};
    k = 3;
    //Output: 2
    result = subarray_sum(nums, k);
    std::cout << result << std::endl;
}




