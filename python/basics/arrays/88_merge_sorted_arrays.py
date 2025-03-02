#https://leetcode.com/problems/merge-sorted-array/
#time O(m+n)
#space O(1)

#meta
'''
TIP: when changing array in-place, try changing from the end.
traverse the 2 arrays from end.. i and j pointers till it reaches the beginning
the highest should be placed starting at the end using a k pointer

if j is exhausted we are done.. 
if j is not exhausted, then we continue with j pointer

#meta
'''
def merge_sorted_arrays(num1: list[int], m, nums2: list[int], n):
    i = m-1
    j = n-1
    k = m + n -1
    while i >= 0 and j >= 0:
        if nums1[i] > nums2[j]:
            nums1[k] = nums1[i]
            i -= 1
        else:
            nums1[k] = nums2[j]
            j -= 1
        k -= 1
    if j >= 0:
        for j1 in range(j, -1, -1):
            nums1[k] = nums2[j1]
            k -= 1
    return nums1




nums1 = [1,2,3,0,0,0]
m = 3
nums2 = [2,5,6]
n = 3
result = merge_sorted_arrays(nums1, m, nums2, n)
print("result = " + str(result))
#Output: [1,2,2,3,5,6]

nums1 = [1]
m = 1
nums2 = []
n = 0
#Output: [1]
result = merge_sorted_arrays(nums1, m, nums2, n)
print("result = " + str(result))

nums1 = [0]
m = 0
nums2 = [1]
n = 1
#Output: [1]
result = merge_sorted_arrays(nums1, m, nums2, n)
print("result = " + str(result))
