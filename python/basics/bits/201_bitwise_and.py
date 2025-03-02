'''
https://leetcode.com/problems/bitwise-and-of-numbers-range/

https://leetcode.com/problems/bitwise-and-of-numbers-range/editorial/
    right shift till left < right
    now leftshift the same numbe of times.
        basically we have to find the common prefix of all numbers..
'''
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        shifts = 0
        while left < right:
            left = left >> 1
            right = right >> 1
            shifts += 1
        return left << shifts
    

left = 5
right = 7
cls = Solution()
result = cls.rangeBitwiseAnd(left, right)
print("result: " + str(result))


left = 0
right = 0
#Output: 0
result = cls.rangeBitwiseAnd(left, right)
print("result: " + str(result))


left = 1
right = 2147483647
#Output: 0
result = cls.rangeBitwiseAnd(left, right)
print("result: " + str(result))
