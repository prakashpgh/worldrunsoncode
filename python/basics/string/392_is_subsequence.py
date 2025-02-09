'''
https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

simple pointer stuff
'''

def is_subsequence(s: str, t: str):
    s_len = len(s)
    t_len = len(t)
    if s == None or len(s) == 0:
        return True
    i = 0
    j = 0
    while i < s_len and j < t_len:
        if s[i] == t[j]:
            i += 1
            if i == s_len:
                return True
        j += 1
    return False


s = "abc"
t = "ahbgdc"
#Output: true
ret = is_subsequence(s, t)
print("is_subsequence: " + str(ret))

s = "axc"
t = "ahbgdc"
#Output: false
ret = is_subsequence(s, t)
print("is_subsequence: " + str(ret))
 
