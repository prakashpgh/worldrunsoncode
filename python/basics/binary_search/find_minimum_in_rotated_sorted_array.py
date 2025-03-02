'''
#https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#find_minimum_in_rotated_sorted_array.py

#this is modified binary search problem.
    get the midpoint in the usual way.
        this is ascending array, rotated... we need to find the smallest numbe
        if n[m] > n[m+1]    => m+1 is the point  
            if n[m-1] > n[m]    => m is the point
            if n[m] > n[l]  => the inflection point is to the right of m, l = m+1
            else
            r = m  

#time O(log N)
#space O(1)
'''

def find_minimum_rotated_sorted_array(nums: list[int]):
    result = 0
    N=len(nums)
    l = 0
    r = N-1
    #no rotations
    if nums[r] > nums[l]:
        return nums[0]

    m=0
    while r > l:
        m = l + (r-l)//2
        if nums[m] > nums[r]:
            l = m + 1
        else:
            r = m
    return nums[l]


nums = [2,1]
result = find_minimum_rotated_sorted_array(nums)
print("result: " + str(result))


nums = [3,4,5,1,2]
result = find_minimum_rotated_sorted_array(nums)
print("result: " + str(result))
#Output: 1
#Explanation: The original array was [1,2,3,4,5] rotated 3 times.


nums = [4,5,6,7,0,1,2]
result = find_minimum_rotated_sorted_array(nums)
print("result: " + str(result))
#Output: 0
#Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.


nums = [11,13,15,17]
result = find_minimum_rotated_sorted_array(nums)
print("result: " + str(result))
#Output: 11
#Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 


nums = [1]
result = find_minimum_rotated_sorted_array(nums)
print("result: " + str(result))
