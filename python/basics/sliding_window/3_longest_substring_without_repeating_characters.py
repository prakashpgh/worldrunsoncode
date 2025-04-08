'''
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150
#O(n)
#O(n)

sliding window problem
    l=r=0
    keep moving r till window is valid.  use dictionary to store the characaters encountered
    once window is invalid, keep moving l till it becomes again valid

#meta
'''


'''
this is a better solution..

'''
def longest_substring_3(s: str) -> int:
    longest = 0
    length = 0
    hash = set()
    N = len(s)
    l = 0
    for r in s:
        while r in hash and l < N:
            hash.remove(s[l])
            l += 1
            length -= 1 #mistake i had set this to zero

        hash.add(r)
        length += 1
        longest = max(longest, length)
    return longest





input = "abcabcbb"

#length = longest_substring_2(input)
length = longest_substring_3(input)
print("longest substring 3: " + str(length))
#3


input = "bbbbb"
length = longest_substring_3(input)
print("longest substring 3: " + str(length))
#1


input = "pwwkew"
#Output: 3
length = longest_substring_3(input)
print("longest substring 3: " + str(length))
#3