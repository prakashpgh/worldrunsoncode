'''
https://leetcode.com/problems/split-array-largest-sum/

this is a capacity problem solved by binary search.

let decide on the max sum of sub array = max(nums) and r=sum(nums) [if we had k = 1]
    calculate m
    now find the subarrays... 

    if count of subarrays < k, then decrease m... r=m
    else
        l=m+1
'''

def find_k_subarrays_with_minimal_sum(nums: list[int], k:int ) -> int:
    l = max(nums)
    r = sum(nums)

    while l <= r:
        m = l + (r-l)//2

        curr_sum = 0
        count = 0
        for i in range(len(nums)):
            curr_sum += nums[i]
            if curr_sum + nums[i] <= m:
                curr_sum += nums[i]
            else:
                curr_sum = 0
                count += 1
    
        if count <= k:
            r = m
        else:
            l = m+1
    return count

