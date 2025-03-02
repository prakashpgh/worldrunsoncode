'''
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

https://www.youtube.com/watch?v=4sQL7R5ySUU

find the occurence as normal binary search...
    if left, search left,
    if right search right
        call the function for both left and right search

#meta
'''

def find_first_last_position_sorted_array(nums: list[int], target: int):

    def search(l:int, r:int, target, left_search: bool):
        l = 0
        r = len(nums) - 1 
        index = -1
        while l <= r:
            m = l + (r-l)//2
            if target > nums[m]:
                l = m + 1
            elif target < nums[m]:
                r = m - 1
            else:
                index = m
                if left_search:
                    r = m -1
                else:
                    l = m + 1
        return index
    
    left = search(0, len(nums)-1, target, True )
    right = search(0, len(nums)-1, target, False )
    return [left, right]


nums = [5,7,7,8,8,10]
target = 8
#Output: [3,4]
result = find_first_last_position_sorted_array(nums, target)
print("result: " + str(result))


nums = [5,7,7,8,8,10]
target = 6
#Output: [-1,-1]
result = find_first_last_position_sorted_array(nums, target)
print("result: " + str(result))


nums = []
target = 0
#Output: [-1,-1]
result = find_first_last_position_sorted_array(nums, target)
print("result: " + str(result))
