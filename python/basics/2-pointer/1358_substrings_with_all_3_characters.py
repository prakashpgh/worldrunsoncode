'''
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
'''
from collections import defaultdict

def substrings_with_all_3_characters(s: str):
    N=len(s)
    num = 0
    counts = defaultdict(int)
    i = 0
    for j in range(N):
        counts[s[j]] += 1
        while i < N and len(counts) == 3:
            num += len(s) - j 
            counts[s[i]] -= 1
            if counts[s[i]] == 0:
                del counts[s[i]]
            i += 1
    return num

s = "aaacb"
#Output: 3
#"aaacb", "aacb" and "acb". 
result = substrings_with_all_3_characters(s)
print("result: " + str(result))


s = "abcabc"
#Output: 10
#"abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
result = substrings_with_all_3_characters(s)
print("result: " + str(result))


s = "abc"
#Output: 1
result = substrings_with_all_3_characters(s)
print("result: " + str(result))

