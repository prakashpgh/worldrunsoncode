'''
1) traditional binary search

2) capacity problems..

3) rotated array
        get the index of min. element using binary search
        case I: no rotation
        case II: left half
        case III: right half
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


#binary search in rotated...
def find_min_index_duplicates(nums: list[int]):
    l = 0
    r = len(nums)-1
    while r > l:   
        m = l + (r-l)//2
        if nums[m] > nums[r]:   #the change in order is occuring here
            l = m+1
        elif nums[m] < nums[r]:
            r = m
        else:
            r -= 1 #we are removing one duplicate.. from rhs.
    return m



nums = [11,12,13,14,15,8,9,10]
target = 0
result = find_min_index(nums)
print("result: " + str(nums) + "=>" + str(result ))

