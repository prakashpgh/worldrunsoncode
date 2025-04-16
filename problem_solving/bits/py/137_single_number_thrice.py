'''
https://leetcode.com/problems/single-number-ii/description/

using maths
    [3 * set(nums)  - sum(nums)] //2
'''

def single_number(nums:list[int]):
    return (sum(set(nums))*3 - sum(nums)) // 2



nums = [2,2,3,2]
#Output: 3
result = single_number(nums)
print("result: " + str(result))

nums = [0,1,0,1,0,1,99]
#Output: 99
result = single_number(nums)
print("result: " + str(result))
