

def binary_search(nums, target):
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
        
    return -1


nums = [-1,0,3,5,9,12]
target = 9
ans = binary_search(nums, target)
print("ans: " + str(ans))
#4

nums = [-1,0,3,5,9,12]
target = 2
#-1
ans = binary_search(nums, target)
print("ans: " + str(ans))
