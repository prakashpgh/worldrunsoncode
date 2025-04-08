'''
https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/

(nums[i] - nums[j]) * nums[k]
precompute the max-right array... by iterating from right

compute the max_left and the max_value from left.

'''

def maximum_value_ordered_triplet(nums: list[int]) -> int:
    n=len(nums)
    max_right = [0] * n
    max_right[n-1] = nums[n-1]
    for k in range(n-2, -1, -1):
        max_right[k] = max(max_right[k+1], nums[k])
    
    max_left = nums[0]
    max_value = 0
    for j in range(1, n-1):
        current_value = (max_left - nums[j])*max_right[j+1]
        max_value = max( max_value, current_value)
        max_left = max(max_left, nums[j])
    if max_value > 0:
        return max_value
    else:
        return 0
    


    



