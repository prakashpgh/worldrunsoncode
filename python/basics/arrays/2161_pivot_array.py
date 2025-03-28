'''
https://leetcode.com/problems/partition-array-according-to-given-pivot/

Approach I: create 3 lists for lower, equal, greater.
    iterate the array.
        fill these lists
    append lists
'''

def pivot_array(nums: list[int], pivot:int) -> list[int]:
    l = 0
    N=len(nums)
    r = N-1
    for i in range(N):
        if nums[i] < pivot:
            tmp = nums[l]
            nums[l] = nums[i]
            nums[i] = tmp
            l += 1
    print(nums)        
    for i in range(N-1,-1, -1):
        if nums[i] > pivot:
            tmp = nums[r]
            nums[r] = nums[i]
            nums[r] = tmp
            r -= 1
    return nums

nums = [9,12,5,10,14,3,10]
print(pivot_array(nums, 10))
