'''
https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150

#O(n)
hashtable[] forward lookup

#meta
'''

def two_sum(nums, target):
    result = []
    hash = {}
    n = len(nums)
    for i in range(n):
        remain = target - nums[i]
        if remain in hash:
            return [i, hash[remain]]
        else:
            hash[nums[i]] = i

    return result


nums = [2,7,11,15]
target = 9
result = two_sum(nums, target)
print("result: " + str(result))

nums = [3,2,4]
target = 6
result = two_sum(nums, target)
print("result: " + str(result))


nums = [3,3]
target = 6
result = two_sum(nums, target)
print("result: " + str(result))