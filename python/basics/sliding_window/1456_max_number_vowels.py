'''
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
'''

def max_number_vowels(s: str, k: int) -> int:
    l = 0
    vowels = "aeiou"
    vowels=set(vowels)
    count = 0
    for i in range(k):
        if s[i] in vowels:
            count += 1
    max_count = count
    N=len(s)
    for r in range(k, N):
        if s[r] in vowels:
            count += 1
        if s[l] in vowels:
            count -= 1
        l += 1
        max_count = max(max_count, count)
    return max_count






s = "abciiidef"
k = 3
#Output: 3
result = max_number_vowels(s, k)
print("result=" + str(result))

s = "aeiou"
k = 2
#Output: 2
result = max_number_vowels(s, k)
print("result=" + str(result))


s = "leetcode"
k = 3
#Output: 2
result = max_number_vowels(s, k)
print("result=" + str(result))
