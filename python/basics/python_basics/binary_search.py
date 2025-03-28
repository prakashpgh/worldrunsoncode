'''
1) traditional binary search

2) capacity problems..

3) rotated array
'''


#binary search in rotated...
def find_min_index(nums: list[int]):
    l = 0
    r = len(nums)-1
    while r > l:   
        m = l + (r-l)//2
        if nums[m] > nums[r]:   #the change in order is occuring here
            l = m+1
        else:
            r = m
    print("change-l: " + str(l) + "=>" + str(nums[l]))
    return m


nums = [11,12,13,14,15,8,9,10]
target = 0
result = find_min_index(nums)
print("result: " + str(nums) + "=>" + str(result ))

