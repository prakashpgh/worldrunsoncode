#https://leetcode.com/problems/maximum-average-subarray-i/description/

def maximum_average_subarray(nums, k):
    N = len(nums)
    if N < k:
        return -1
    
    l = 0
    sum = 0
    for i in range(k):
        sum += nums[i]
    max_sum = sum
    for r in range(k, N):
        sum += nums[r]
        sum -= nums[l]
        max_sum = max(max_sum, sum)
        l += 1
    return max_sum/k



nums = [1,12,-5,-6,50,3]
k = 4
result = maximum_average_subarray(nums, k)
print("result: " + str(result))
#Output: 12.75000
#Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75


nums = [5]
k = 1
result = maximum_average_subarray(nums, k)
print("result: " + str(result))

#Output: 5.00000