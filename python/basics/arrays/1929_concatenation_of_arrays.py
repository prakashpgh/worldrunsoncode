'''
https://leetcode.com/problems/concatenation-of-array/description/
'''

def concatenation_of_arrays(array: list[int]):
    result = []
    repeat = 2
    for r in range(repeat):
        for i in array:
            result.append(i)
    return result




nums = [1,2,1]
#Output: [1,2,1,1,2,1]
result = concatenation_of_arrays(nums)
print("original: " + str(nums) + " result: " + str(result))

nums = [1,3,2,1]
result = concatenation_of_arrays(nums)
#output: [1,3,2,1,1,3,2,1]
print("original: " + str(nums) + " result: " + str(result))

