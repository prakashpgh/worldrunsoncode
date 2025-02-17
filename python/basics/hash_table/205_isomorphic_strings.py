'''
https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

#mistake simple problem, but missed the 2 way mapping
'''


def is_isomorphic(s:str, t:str) -> bool:
    if not s and not t:
        return True
    if len(s) != len(t):
        return False
    len_s = len(s)
    len_t = len(t)
    map_skey = {}
    map_tkey = {}
    for i in range(len_s):
        if s[i] in map_skey and map_skey[s[i]] != t[i]:
            return False
        if t[i] in map_tkey and map_tkey[t[i]] != s[i]:
            return False
        
        map_skey[s[i]] = t[i]
        map_tkey[t[i]] = s[i]
    return True


s="badc"
t="baba"
ret = is_isomorphic(s, t)
print("ret: " + str(ret))


s = "egg"
t = "add"
#Output: true
#he strings s and t can be made identical by:
ret = is_isomorphic(s, t)
print("ret: " + str(ret))

s = "foo"
t = "bar"
#Output: false
ret = is_isomorphic(s, t)
print("ret: " + str(ret))


s = "paper"
t = "title"
#Output: true
ret = is_isomorphic(s, t)
print("ret: " + str(ret))
