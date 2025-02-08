

def binary_search_location(nums, target):
    n = len(nums)
    l = 0
    r = n-1
    
    while(r >= l):
        m = l + (r-1)//2
        if target == nums[m]:
            return m
        elif target > nums[m]:
            l = m+1
        elif target < nums[m]:
            r = m-1
        
    if nums[m] < target:
        return m+1
    else:
        return m


nums = [1,3,5,6]
target = 5
#ans = binary_search_location(nums, target)
#print("ans: " + str(ans))
#2

nums = [1,3,5,6]
target = 2
#1
#ans = binary_search_location(nums, target)
#print("ans: " + str(ans))

nums = [1,3,5,6]
target = 7
#4
ans = binary_search_location(nums, target)
print("ans: " + str(ans))
