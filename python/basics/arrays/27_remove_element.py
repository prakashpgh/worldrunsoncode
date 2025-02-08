#https://leetcode.com/problems/remove-element/description/
#a-2
'''
O(n)
space: O(1)
iterate from beginning 
Idea is if we encounter target, replace it from end with non-target.
kind of 2-pointer approach
'''

def remove_element(nums, target):
    N=len(nums)
    j = N-1
    for i in range(N):
        if j < i:
            break
        if nums[i] == target:
            while j > i and nums[j] == target:
                j -= 1
            nums[i] = nums[j]
            j -= 1

    return j+1



nums = [3,2,2,3]
val = 3
result = remove_element(nums, val)
print("result: input:" + str(nums) + " remove: " + str(val) + " result: " + str(result) + str(nums))
#Output: 2, nums = [2,2,_,_]


nums = [0,1,2,2,3,0,4,2]
val = 2
result = remove_element(nums, val)
print("result: input:" + str(nums) + " remove: " + str(val) + " result: " + str(result) + str(nums))

#Output: 5, nums = [0,1,4,0,3,_,_,_]