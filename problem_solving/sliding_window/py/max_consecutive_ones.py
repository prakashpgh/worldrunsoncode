#https://leetcode.com/problems/max-consecutive-ones-iii/description/

def max_consecutive_ones(nums, k):
    N = len(nums)
    max_width = 0
    l = 0
    zeros = 0
    for r in range(N):
        if nums[r] == 0:
            zeros += 1
        while zeros > k and l < N:
            if nums[l] == 0:
                zeros -= 1
            l += 1

        w = r - l + 1
        max_width = max(w, max_width)
    return max_width


nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2
result = max_consecutive_ones(nums, k)
print("result: " + str(result))
#Output: 6
#Explanation: [1,1,1,0,0,1,1,1,1,1,1]

nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
k = 3
result = max_consecutive_ones(nums, k)
print("result: " + str(result))
#Output: 10
