#https://leetcode.com/problems/search-in-rotated-sorted-array

'''
mistake: be careful about the indexes...

1) first find the min... element index.. index of the min. element.

2) then you break the array into 3 parts, => when minIndex = 0, the part before min index, and part after min index.... depending on the target.

3) then apply the normal binary search
'''
def search_in_rotated_array(nums: list[int], target):
    N=len(nums)
    l = 0
    r = N-1

    while r > l:   
        m = l + (r-l)//2
        if nums[m] > nums[r]:   #the change in order is occuring here
            l = m+1
        else:
            r = m
    print("change-l: " + str(l) + "=>" + str(nums[l]))

    #case i: m = 0
    min_index = l
    if min_index == 0:
        l = 0
        r = N-1
    elif target >= nums[0] and target <= nums[min_index-1]:
        r = min_index-1
        l = 0
    else: 
        l = min_index
        r = N-1
    #
    print("search: " + str(l) + " , " + str(r) + " target: " + str(target))
    while r >= l:
        m = l + (r-l)//2
        if nums[m] == target:
            return m
        elif nums[m] < target:
            l=m+1
        else:
            r=m-1
    return -1


nums = [11,12,13,14,15,8,9,10]
target = 8
result = search_in_rotated_array(nums, target)
print("result: " + str(nums) + " target: " + str(target) + "=>" + str(result ))
exit(0)

nums = [1]
target = 1
result = search_in_rotated_array(nums, target)
print("result: " + str(nums) + " target: " + str(target) + "=>" + str(result ))




target = 12
result = search_in_rotated_array(nums, target)
print("result: " + str(nums) + " target: " + str(target) + "=>" + str(result ))




nums = [5,1,3]
target = 5
result = search_in_rotated_array(nums, target)
print("result: " + str(nums) + " target: " + str(target) + "=>" + str(result ))



nums = [0,1,2,3,4,5,6,7]
target = 0
result = search_in_rotated_array(nums, target)
print("result: " + str(nums) + " target: " + str(target) + "=>" + str(result ))


nums = [4,5,6,7,0,1,2]
target = 3
result = search_in_rotated_array(nums, target)
print("result: " + str(nums) + " target: " + str(target) + "=>" + str(result ))
#Output: -1

nums = [1]
target = 0
#Output: -1
result = search_in_rotated_array(nums, target)
print("result: " + str(target) + "=>" + str(result ))
