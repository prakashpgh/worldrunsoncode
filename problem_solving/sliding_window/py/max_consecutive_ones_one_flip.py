#https://leetcode.com/problems/max-consecutive-ones-ii/description/

def max_consecutive_ones_max_one_flip(nums: list[int], allowed_flips):
    N=len(nums)
    count = 0
    zeros = 0
    ALLOWED_FLIPS = allowed_flips

    l = 0
    max_width = 0

    for r in range(N):
        if nums[r] == 0:
            zeros += 1
        
        while zeros > allowed_flips and l < N:
            if nums[l] == 0:
                zeros -= 1
            l += 1
        
        w = r - l + 1
        max_width = max(w, max_width)
    return max_width




nums = [1,0,1,1,0]
flips = 1
result = max_consecutive_ones_max_one_flip(nums,flips)
print("result: " + str(result))

nums = [1,0,1,1,0,1]
#4
flips = 1
result = max_consecutive_ones_max_one_flip(nums,flips)
print("result: " + str(result))
