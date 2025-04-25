'''
Given an array of numbers N and an integer k, your task is to split N into k partitions such that the maximum sum of any partition is minimized. Return this sum.

For example, given N = [5, 1, 2, 7, 3, 4] and k = 3, you should return 8, since the optimal partition is [5, 1, 2], [7], [3, 4].
'''

def split_arrays(nums: list[int], k: int) -> int:
    l= max(nums)
    r = sum(nums)
    result = []
    while l < r:
        partitions = 1
        curr_sum = 0
        
        m = (l + r) // 2
        print(" l: " + str(l) + " r: " + str(r) + " m: " + str(m))
        for num in nums:
            if curr_sum + num <= m:
                curr_sum += num
            else:
                curr_sum = num
                partitions += 1
        if partitions > k:
            l = m + 1
        else:
            r = m
    return l


N = [5, 1, 2, 7, 3, 4]
k = 3
print(split_arrays(N, k))  # Output: 8







