'''
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

sliding window
r- for loop
'''


def longest_subarray_after_deleting_ones(nums: list[int]) -> int:
    N=len(nums)
    l = 0
    zeros = 0
    max_len = 0
    for r in range(N):
        if nums[r] == 0:
            zeros += 1
            while l <= N and zeros > 1:
                if nums[l] == 0:
                    zeros -= 1
                l += 1
        max_len = max(max_len, r-l)
    return max_len    

nums = [1,1,0,1]
#Output: 3
result = longest_subarray_after_deleting_ones(nums)
print("result= " + str(result))

nums = [0,1,1,1,0,1,1,0,1]
#Output: 5
result = longest_subarray_after_deleting_ones(nums)
print("result= " + str(result))


nums = [1,1,1]
#Output: 2
result = longest_subarray_after_deleting_ones(nums)
print("result= " + str(result))
