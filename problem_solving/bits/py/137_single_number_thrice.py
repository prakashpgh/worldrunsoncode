'''
https://leetcode.com/problems/single-number-ii/description/

using maths
    [3 * set(nums)  - sum(nums)] //2
'''

def single_number(nums:list[int]):
    return (sum(set(nums))*3 - sum(nums)) // 2


def single_number_using_bits(nums:list[int]):
    ones = 0
    twos = 0
    for num in nums:
        twos |= ones & num
        ones ^= num
        threes = twos & ones
        ones &= ~threes
        twos &= ~threes
    return ones;




nums = [2,2,3,2]
#Output: 3
result = single_number(nums)
print("result: " + str(result))
result = single_number_using_bits(nums)
print("result-bits: " + str(result))

nums = [0,1,0,1,0,1,99]
#Output: 99
result = single_number(nums)
print("result: " + str(result))

result = single_number_using_bits(nums)
print("result-bits: " + str(result))
