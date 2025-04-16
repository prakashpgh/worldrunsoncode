'''
https://leetcode.com/problems/longest-palindromic-substring
https://www.youtube.com/watch?v=XYQecbcd6_c
Idea:
    for each character, check if its a palindrome going outwards
        for odd, i=j
        for even i=j+1  

        O(N**2)
'''
def longest_palindromic_substring(s:str) -> bool:
    N=len(s)
    res = ""
    res_len = 0
    for i in range(len(s)):
        #odd
        l, r = i, i
        while l >= 0 and r < N and s[l] == s[r]:
            if r-l+1 > res_len:
                res_len = r-l+1
                res = s[l:r+1]
            l -= 1
            r += 1  #mistake... note we are moving away from center
        #even
        l, r = i, i+1
        while l >= 0 and r < N  and r>l and s[l] == s[r]:
            if r-l+1 > res_len:
                res_len = r-l+1
                res = s[l:r+1]
            l -= 1
            r += 1
    return res

s = "babad"
#Output: "bab"
result = longest_palindromic_substring(s)
print("result: " + result)

s = "cbbd"
#Output: "bb"
result = longest_palindromic_substring(s)
print("result: " + result)
