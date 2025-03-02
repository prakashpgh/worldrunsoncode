'''
https://leetcode.com/problems/single-element-in-a-sorted-array/description/

xor with the same int gives 0

#meta
'''


def single_element_in_sorted_array(nums: list[int]) -> int:
    result = 0
    for n in nums:
        result ^= n
    return result




nums = [1,1,2,3,3,4,4,8,8]
#Output: 2
result = single_element_in_sorted_array(nums)
print("result:" + str(result))

nums = [3,3,7,7,10,11,11]
#Output: 10
result = single_element_in_sorted_array(nums)
print("result:" + str(result))
