'''
https://leetcode.com/problems/find-pivot-index/
'''

def pivot_index(nums: list[int]) -> int:
    sum = 0
    N = len(nums)
    for n in nums:
        sum += n
        
    left_sum = 0
    for i in range(N):
        if sum - left_sum - nums[i] == left_sum:
            return i
        left_sum += nums[i]
    return -1






