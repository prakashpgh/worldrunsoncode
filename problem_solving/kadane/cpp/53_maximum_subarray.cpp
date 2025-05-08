/*
#https://leetcode.com/problems/maximum-subarray/description/

for (int i = 1; i < nums.size(); ++i) {
            current_max = max(nums[i], current_max + nums[i]);
            max_so_far = max(max_so_far, current_max);
        }

*/



import sys

def max_sub_array_largest_sum_my(nums):
    max_sum = float('-inf')
    sum = 0.0
    for n in nums:
        sum += n
        sum = max(sum, n)
        max_sum = max(sum, max_sum)
    return int(max_sum)


def max_sub_array_largest_sum(nums):
    N=len(nums)

    sum1 = 0
    max_sum = float('-inf')
    for i in range(N):
        sum1 += nums[i]
        max_sum = max(max_sum, sum1)
        if sum1 < 0:
            sum1 = 0
    return max_sum

nums=[-2,7,-3,4]
result = max_sub_array_largest_sum(nums)
print("result: " + str(result))
#8

nums = [-2,1,-3,4,-1,2,1,-5,4]
#Output: 6
#[4,-1,2,1]
result = max_sub_array_largest_sum(nums)
print("result: " + str(result))

nums = [1]
#Output: 1
#Explanation: The subarray [1] has the largest sum 1.
result = max_sub_array_largest_sum(nums)
print("result: " + str(result))


nums = [5,4,-1,7,8]
##Output: 23
#Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
result = max_sub_array_largest_sum(nums)
print("result: " + str(result))
