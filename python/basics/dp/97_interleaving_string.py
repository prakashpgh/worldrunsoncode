'''
https://leetcode.com/problems/interleaving-string/

https://www.youtube.com/watch?v=oRYUnwklC98

Approach I: recursion
    if the character matches, then try the next character..
    try with both the strings if charactermatches.

    base case: sum of lengths, all indexes reach the lengths of the strings
'''

def interleaving_string_recursion(s1:str, s2:str, s3: str) -> bool:
    A1 = len(s1)
    A2 = len(s2)
    N = len(s3)
    memo = {}
    if A1+A2 != N:
        return False
    def recur(i, j, k):
        ret1=False
        ret2=False
        if i == A1 and j == A2 and k == N:
            return True
        if (i,j,k) in memo:
            return memo[(i,j,k)]
        if i < A1 and s1[i] == s3[k]:
            ret1 = recur(i+1, j, k+1)    
        if j < A2 and s2[j] == s3[k]:
            ret2 = recur(i, j+1, k+1)    
        memo[(i,j,k)]=ret1 or ret2
        return memo[(i,j,k)]
    return recur(0,0,0)




s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"
#Output: true
result = interleaving_string_recursion(s1, s2, s3)
print("result: " + str(result))


s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbbaccc"
#Output: false
result = interleaving_string_recursion(s1, s2, s3)
print("result: " + str(result))


s1 = ""
s2 = ""
s3 = ""
#Output: true
result = interleaving_string_recursion(s1, s2, s3)
print("result: " + str(result))
