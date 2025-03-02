#https://leetcode.com/problems/maximum-subarray/description/

import sys

def max_sub_array_largest_sum_my(nums):
    N=len(nums)
    if N==0:
        return []
    sum1 = nums[0]
    max_sum = sum1
    ans_start = 0
    ans_end = 0
    start = 0
    end = 0
    for i in range(1, N):
        if sum1 < 0:
            sum1 = 0
            start = i
            end = i
        sum1 += nums[i]
        if sum1 > max_sum:
            max_sum = sum1
            ans_start = start
            ans_end = i
    result = nums[ans_start: ans_end+1]
    print("type: " + str(type(result)))
    return sum(result)
    #return result


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
