'''
https://leetcode.com/problems/unique-number-of-occurrences/

hashtable
set

fill in has hashtable...
use set to check if the values repeat
'''

def unique_number_of_occurences(nums: list[int]):
    hash = {}
    for n in nums:
        if n not in hash:
            hash[n] = 1
        else:
            hash[n] += 1
    freq = set()
    for h in hash.values():
        if h in freq:
            return False
        else:
            freq.add(h)
    return True




arr = [1,2,2,1,1,3]
#Output: true
result = unique_number_of_occurences(arr)
print("result: " + str(result))


arr = [1,2]
#Output: false
result = unique_number_of_occurences(arr)
print("result: " + str(result))


arr = [-3,0,1,-3,1,1,1,-3,10,0]
#true
result = unique_number_of_occurences(arr)
print("result: " + str(result))
