'''
https://leetcode.com/problems/merge-strings-alternately/
'''

def merge_strings_alternately(s1: str, s2: str) -> str:
    n1= len(s1)    
    n2= len(s2)    
    i = 0
    j = 0
    result = []
    while i < n1 or j < n2:
        if i < n1:
            result.append(s1[i])
            i += 1
        if j < n2:
            result.append(s2[j])
            j += 1
    return "".join(result)
        






word1 = "abc"
word2 = "pqr"
#Output: "apbqcr"
result = merge_strings_alternately(word1, word2)
print("result=" + result)

word1 = "ab"
word2 = "pqrs"
#Output: "apbqrs"
result = merge_strings_alternately(word1, word2)
print("result=" + result)

word1 = "abcd"
word2 = "pq"
#Output: "apbqcd"
result = merge_strings_alternately(word1, word2)
print("result=" + result)