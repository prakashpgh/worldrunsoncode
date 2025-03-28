'''
https://leetcode.com/problems/valid-triangle-number/
    sort the array
    consider the longest side from the array..  as 2nd index.. since [0] and [1] will be smaller
    now using 2-pointer technique, from 0 to k-1, 
    l = 0 
    r = k-1
        if less, then i++
        else,
            j-1 possible combinations
            j--
#revisit
'''

def triangleNumber(nums):
    nums.sort()  # Sort the array
    count = 0
    n = len(nums)
    
    for k in range(2, n):  # Fix the largest side c
        i = 0  # Left pointer for a
        j = k - 1  # Middle pointer for b
        while i < j:
            if nums[i] + nums[j] > nums[k]:
                count += j - i  # All pairs (i, j), (i+1, j), ..., (j-1, j) are valid
                j -= 1  # Move j left to check smaller sums
            else:
                i += 1  # Move i right to increase the sum
    return count