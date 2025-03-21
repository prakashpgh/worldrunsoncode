'''
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
'''

#https://leetcode.com/problems/subarray-sum-equals-k/description/
#t: O(n)
#s: O(n)

def subarray_sum(nums: list[int], k:int) -> int: 
    presum = {0: 1}
    curr_sum = 0
    count = 0
    for i in range(len(nums)):
        curr_sum += nums[i]
        if (curr_sum - k)  in presum:
            count += presum[curr_sum - k]
        
        presum[curr_sum] = presum.get(curr_sum, 0) + 1
    return count




nums = [1,-1,1]
k = 1
result = subarray_sum(nums, k)
print("result=" + str(result))
