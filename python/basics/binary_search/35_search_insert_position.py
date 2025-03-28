#https://leetcode.com/problems/search-insert-position/description/

'''
this is vanilla binary search, with finding the nearest number..
'''
def search_index_position(nums: list[int], target: int) -> int:
    result = -1
    N = len(nums)
    l = 0
    r = N-1
    while r >= l:
        m = l + (r-l)//2
        if nums[m] == target:
            return m
        elif nums[m] < target:
            l = m+1
        else:
            r = m-1
    if nums[m] < target:
        return m+1
    else:
        return m

    return result







nums = [1,3,5,6]
target = 5
index = search_index_position(nums, target)
print("index: " + str(index))
#Output: 2


nums = [1,3,5,6]
target = 2
index = search_index_position(nums, target)
print("index: " + str(index))
#Output: 1


nums = [1,3,5,6]
target = 7
index = search_index_position(nums, target)
print("index: " + str(index))
#Output: 4