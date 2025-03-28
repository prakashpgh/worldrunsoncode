'''
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
'''


def minimum_in_sorted_rotated_array_with_duplicates(nums: list[int]) -> int:
    l=0
    r = len(nums)-1
    while l < r:
        m = l + (r-l)//2
        if nums[m] > nums[right]:
            l = m+1
        elif nums[l] <  nums[m]:
            r = m
        else:
            #only arises in case of duplicate case
            r -= 1
    return -1
