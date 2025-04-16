'''
https://leetcode.com/problems/next-greater-element-i
'''

def next_greater_element(nums1: list[int], nums2: list[int]):
    stack = []
    mapping = {}
    for i, num in enumerate(nums2):
        while stack and stack[len(stack)-1] < num:
            mapping[stack.pop()] = nums2[i]
        stack.append(nums2[i])
    result = []
    for num in nums1:
        if num not in mapping:
            result.append(-1)
        else:
            result.append(mapping[num])
    return result


        
nums1 = [4,1,2]
nums2 = [1,3,4,2]
result = next_greater_element(nums1, nums2)
print("result: " + str(result))
#Output: [-1,3,-1]



nums1 = [2,4]
nums2 = [1,2,3,4]
#Output: [3,-1]
result = next_greater_element(nums1, nums2)
print("result: " + str(result))

