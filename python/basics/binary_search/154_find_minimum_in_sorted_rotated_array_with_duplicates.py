'''
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

here the array can contain duplicates  => thats the difference between 33
'''


def minimum_in_sorted_rotated_array_with_duplicates(nums: list[int]) -> int:
    l=0
    r = len(nums)-1
    while l < r:
        m = l + (r-l)//2
        if nums[m] > nums[r]:
            l = m+1
        elif nums[l] <  nums[m]:
            r = m
        else:
            #only arises in case of duplicate case
            r -= 1
    return nums[l]




nums = [1, 3, 5]
result = minimum_in_sorted_rotated_array_with_duplicates(nums)
print("result=" + str(result))


nums = [2, 2, 2, 0, 1]
result = minimum_in_sorted_rotated_array_with_duplicates(nums)
print("result=" + str(result))



nums = [3,3,1,3]
result = minimum_in_sorted_rotated_array_with_duplicates(nums)
print("result=" + str(result))
