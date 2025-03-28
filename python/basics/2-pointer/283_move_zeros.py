'''
https://leetcode.com/problems/move-zeroes/description/

for loop for r...
keep a pointer to track the non-zero..

#check
'''

def move_zeros(nums: list[int]):
    if not nums:
        return []
    l= 0
    N = len(nums)
    for i in range(N):
        if nums[i] != 0:
            if l != i:
                tmp = nums[l]
                nums[l] = nums[i]
                nums[i] = tmp
            l += 1







nums = [1,1,0,3,12]
print("before: " + str(nums))
move_zeros(nums)
print("after: " + str(nums))

nums = [1,1,0,3,12]
move_zeros_2(nums)
print("after: " + str(nums))


nums = [0,1,0,3,12]
print("before: " + str(nums))
#Output: [1,3,12,0,0]
move_zeros(nums)
print("after: " + str(nums))

nums = [0,1,0,3,12]
move_zeros_2(nums)
print("after: " + str(nums))


nums = [0]
#Output: [0]