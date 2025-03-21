'''

2215_find_difference_of_two_arrays.py
'''

def find_difference_of_two_arrays(nums1: list[int], nums2: list[int]) -> list[list[int]]:
    set1 = set(nums1)
    set2 = set(nums2)
    return [list(set1 - set2), list(set2 - set1)]



nums1 = [1,2,3]
nums2 = [2,4,6]
#Output: [[1,3],[4,6]]
result = find_difference_of_two_arrays(nums1, nums2)
print("result = " + str(result))

nums1 = [1,2,3,3]
nums2 = [1,1,2,2]
#Output: [[3],[]]
result = find_difference_of_two_arrays(nums1, nums2)
print("result = " + str(result))
