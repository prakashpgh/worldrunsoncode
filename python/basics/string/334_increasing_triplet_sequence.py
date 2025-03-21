'''
https://leetcode.com/problems/increasing-triplet-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

#tricky
iterate the numbers
    keep updating first to its lowest
    else keep updating second to its lowest
'''


def increasing_triplet_sequence(nums: list[int]):
    first = float('inf')
    second = float('inf')
    indexes = []
    for i in range(len(nums)):
        if nums[i] <= first:
            first = nums[i]
        elif nums[i] <= second:
            second = nums[i]
        else:
            return True
    return False
        





nums = [1,2,3,4,5]
#Output: true
#Explanation: Any triplet where i < j < k is valid.
result = increasing_triplet_sequence(nums)
print("result:" + str(result))


nums = [5,4,3,2,1]
#Output: false
result = increasing_triplet_sequence(nums)
print("result:" + str(result))


nums = [2,1,5,0,4,6]
#Output: true
result = increasing_triplet_sequence(nums)
print("result:" + str(result))
