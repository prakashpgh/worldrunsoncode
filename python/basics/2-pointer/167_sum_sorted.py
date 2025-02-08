'''
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

use 2 pointer technique
'''

def two_sum_sorted(input, target):
    l = 0
    r = len(input)-1
    while l < r:
        sum = input[l] + input[r]
        if sum == target:
            return [l+1, r+1]
        elif sum < target:
            l += 1
        else:
            r -= 1

    return [-1,-1]




numbers = [2,7,11,15]
target = 9
result = two_sum_sorted(numbers, target)
print("result: " + str(result))
#Output: [1,2]
#Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].


numbers = [2,3,4]
target = 6
#Output: [1,3]
#Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
result = two_sum_sorted(numbers, target)
print("result: " + str(result))


numbers = [-1,0]
target = -1
#Output: [1,2]
#Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
result = two_sum_sorted(numbers, target)
print("result: " + str(result))
