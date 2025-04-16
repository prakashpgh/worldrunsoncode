'''
https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150

'''
import re

def word_pattern(pattern:str, s:str) -> bool:
    len_s = len(s)    
    len_p = len(pattern)

    s = re.sub(r'^\s+', '', s)
    if pattern is None and s is None:
        return True
    #extract words
    words = []
    index = 0
    i = 0
    while i < len_s:
        while i < len_s and s[i] == " ":
            i += 1
        index=i
        while i < len_s and s[i] != " ":
            i += 1
        words.append(s[index:i])
    print("words: " + str(words))
    dict_pattern_key = {}
    dict_s_key = {}
    #check length
    if len_p != len(words):
        return False
    #patten as key
    for i in range(len_p):
        if pattern[i] in dict_pattern_key and dict_pattern_key[pattern[i]] != words[i]:
            return False
        dict_pattern_key[pattern[i]] = words[i]
    #words as key
    for i in range(len(words)):
        if words[i] in dict_s_key and dict_s_key[words[i]] != pattern[i]:
            return False
        dict_s_key[words[i]] = pattern[i]
    return True

pattern = "abba"
s = "dog cat cat dog"
#Output: true
result = word_pattern(pattern,s)
print("result: " + str(result))


pattern = "abba"
s = "dog cat cat fish"
#Output: false
result = word_pattern(pattern,s)
print("result: " + str(result))



pattern = "aaaa"
s = "dog cat cat dog"
#Output: false
result = word_pattern(pattern,s)
print("result: " + str(result))
