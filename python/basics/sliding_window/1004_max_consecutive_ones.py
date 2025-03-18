'''
https://leetcode.com/problems/max-consecutive-ones-iii/
sliding windows

'''

def max_consecutive_ones(nums: list[int], k: int):
    l = 0
    N=len(nums)
    max_ones = 0
    zeros = 0
    for r in range(N):
        if nums[r] == 0:
            zeros += 1
        while zeros > k and l < N:
            if l < N and nums[l] == 0:
                zeros -= 1
            l += 1
        window = r-l+1
        max_ones = max(max_ones, window)
    return max_ones




nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2
#Output: 6
result =  max_consecutive_ones(nums, k)
print("result: " + str(result))

nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
k = 3
#Output: 10
result =  max_consecutive_ones(nums, k)
print("result: " + str(result))
