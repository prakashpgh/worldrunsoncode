'''
https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150

approach i: sort the strings and the strings should be identical
lengths should be same
'''

def valid_anagram(s, t):
    if len(s) != len(t):
        return False
    freq_counter = [0]*26
    for i in range(len(s)):
        freq_counter[ord(s[i])-ord('a')] += 1
        freq_counter[ord(t[i])-ord('a')] -= 1
    for f in freq_counter:
        if f != 0:
            return False
    return True


s = "anagram"
t = "nagaram"
result = valid_anagram(s, t)
print("result: " + str(result))
#True

s = "rat"
t = "car"
result = valid_anagram(s, t)
print("result: " + str(result))
#False