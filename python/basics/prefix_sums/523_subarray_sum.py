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
    N=len(nums)
    prefixes = [0]*N

    prefixes[0]=nums[0] % k
    for i in range(1,N):
        prefixes[i] = (prefixes[i-1] + nums[i]) % k
    prefix_frequency=set()
    
    for i in range(N):
        if prefixes[i] in prefix_frequency:
            return True
        prefix_frequency.add(prefixes[i])
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
