'''
https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150
#mistake in understanding the problem
    tricky problem
'''

def contains_duplicates_k(nums: list[int], k:int) -> bool:
    duplicate_dict = {}
    for i in range(len(nums)):
        if nums[i] in duplicate_dict:
            index = duplicate_dict[nums[i]]
            if abs(i- index) <= k:
                return True
            else:
                duplicate_dict[nums[i]] = i
        else:
            duplicate_dict[nums[i]] = (i) 
    return False


nums = [1,2,3,1]
k = 3
#Output: true
result = contains_duplicates_k(nums,k)
print("contains duplicates: " + str(result))

nums = [1,0,1,1]
k = 1
#Output: true
result = contains_duplicates_k(nums,k)
print("contains duplicates: " + str(result))


nums = [1,2,3,1,2,3]
k = 2
#Output: false
result = contains_duplicates_k(nums,k)
print("contains duplicates: " + str(result))

