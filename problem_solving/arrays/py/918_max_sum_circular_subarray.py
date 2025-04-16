'''
https://leetcode.com/problems/maximum-sum-circular-subarray/

https://www.youtube.com/watch?v=vxer7ns7BIs
https://www.youtube.com/watch?v=fxT9KjakYPM&t=708s   ***

Idea:
    the max subarray can be in the 1) middle  or 2) beginning + end.
        if its at the beginning + end => total - min_subarray
        
    1) find the normal max sub array.
    2) find the min sub array in similar manner
    3) find total
    4) max( maxsub, sum - min_sub)  if maxsub > 0, else max_sub

'''

def maxSubarraySumCircular(self, nums: list[int]) -> int:
    max_sum = float('-inf')
    sum_x = float('-inf')
    min_sum = float('inf')
    sum_m = float('inf')
    total = 0.0
    for n in nums:
        sum_x = max(sum_x + n, n)
        max_sum = max(max_sum, sum_x)

        sum_m = min(sum_m+n, n)
        min_sum = min(sum_m, min_sum)
        total += n
    max_sum = max(max_sum, total - min_sum) if max_sum > 0 else max_sum
    return int(max_sum)




nums = [1,-2,3,-2]
#Output: 3


nums = [5,-3,5]
#Output: 10


nums = [-3,-2,-3]
#Output: -2
