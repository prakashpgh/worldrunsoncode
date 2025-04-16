'''
https://leetcode.com/problems/continuous-subarray-sum/description/

Approach I: brute force
    O(N***3)

    the sum of the subarray is divisible by k

    find presum.
    find presummod  presum/mod

    traverse this.. and check if its same using hashmap
'''

def subarray_sum_divisible_by_k(nums: list[int], k: int) -> bool:
    if k == 0:
        for num in range(len(nums)-1):
            if nums[i] == 0 and nums[i+1] == 0:
                return True
        return False
    remainder_map = {0: -1}
    sum = 0
    for i, num  in enumerate(nums):
        sum += num
        remain = sum % k
        if remain in remainder_map:
            if i - remainder_map[remain] > 1:
                return True
        else:
            remainder_map[remain] = i
    return False

            

nums = [23,2,4,6,7]
k = 6
#Output: true
result = subarray_sum_divisible_by_k(nums, k)
print("result: " + str(result))


nums = [23,2,6,4,7]
k = 6
#Output: true
result = subarray_sum_divisible_by_k(nums, k)
print("result: " + str(result))


nums = [23,2,6,4,7]
k = 13
#Output: false
result = subarray_sum_divisible_by_k(nums, k)
print("result: " + str(result))
