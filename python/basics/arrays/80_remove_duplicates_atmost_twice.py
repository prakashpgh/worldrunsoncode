#https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

#time O(n)
#space O(1)
'''
maintain reader and writer pointer
keep a count of the duplicates
'''
def remove_duplicates_atmost_twice(nums: list[int]):
    N = len(nums)
    j = 1
    count = 1
    for i in range(1,N):
        if nums[i] != nums[i-1]:
            count = 1
        else:
            count += 1
        
        if count <= 2:
            nums[j] = nums[i]
            j += 1
    return j

nums = [0,0,1,1,1,1,2,3,3]
#Output: 7, nums = [0,0,1,1,2,3,3,_,_]
result = remove_duplicates_atmost_twice(nums)
print("result: " + str(result) + str(nums))

nums = [1,1,1,2,2,3]
#Output: 5, nums = [1,1,2,2,3,_]
result = remove_duplicates_atmost_twice(nums)
print("result: " + str(result) + str(nums))

