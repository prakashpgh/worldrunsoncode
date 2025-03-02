'''
https://leetcode.com/problems/find-peak-element/



O(log N)
'''

def find_peak_element(nums:list[int]) -> bool:  
    l = 0
    r = len(nums) - 1
    while l < r:
        m = l + (r - l)//2
        if nums[m] > nums[m+1]:
            r = m
        else:
            l = m + 1
    return l






nums = [1,2,3,1]
#Output: 2
result = find_peak_element(nums)
print("result: " + str(result))


nums = [1,2,1,3,5,6,4]
#Output: 5
result = find_peak_element(nums)
print("result: " + str(result))
