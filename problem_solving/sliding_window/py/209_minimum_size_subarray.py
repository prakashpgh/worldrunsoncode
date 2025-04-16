#https://leetcode.com/problems/minimum-size-subarray-sum/description/
'''
t: O(n)
note that its sliding window..
'''

import sys

def minimum_size_subarray_sum(target, nums):
    N = len(nums)
    min_size = sys.maxsize
    l = 0
    sum = 0
    for r in range(N):
        sum += nums[r]
        while sum >= target and l < N:
            min_size = min(min_size, r-l+1) #did mistake here.
            sum -= nums[l]  #kool trick
            l += 1
    if min_size == sys.maxsize:
        min_size = 0
    return min_size




target = 7
nums = [2,3,1,2,4,3]
result = minimum_size_subarray_sum(target, nums)
print("result: " + str(result))
#Output: 2
#Explanation: The subarray [4,3] has the minimal length under the problem constraint.


target = 4
nums = [1,4,4]
result = minimum_size_subarray_sum(target, nums)
print("result: " + str(result))

#Output: 1


target = 11
nums = [1,1,1,1,1,1,1,1]
result = minimum_size_subarray_sum(target, nums)
print("result: " + str(result))

#Output: 0