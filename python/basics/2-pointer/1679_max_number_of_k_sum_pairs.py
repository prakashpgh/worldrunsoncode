'''
https://leetcode.com/problems/max-number-of-k-sum-pairs

#tricky
'''


def max_number_of_k_sum_pairs(nums: list[int], k:int ) -> int:
    hash = {}
    count = 0
    for i in range(len(nums)):
        comp = k - nums[i]
        if comp in hash and hash[comp] > 0:
            count += 1
            hash[comp] -= 1
        else:                
            hash[nums[i]] = hash.get(nums[i], 0) + 1
    return count



nums = [1,2,3,4]
k = 5
#Output: 2
result = max_number_of_k_sum_pairs(nums, k)
print("result: " + str(result))

nums = [3,1,3,4,3]
k = 6
#Output: 1
result = max_number_of_k_sum_pairs(nums, k)
print("result: " + str(result))
