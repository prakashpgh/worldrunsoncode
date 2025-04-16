'''
https://leetcode.com/problems/valid-palindrome-ii/description

Idea:
using l and r, check if the characters of string match.
if they dont match, call the function checkPalindrome with the current l+1,r   and l, r-1.  
if either of these are palindromes, return true
'''

def valid_palindrome(s: str) -> bool:
    def check_palindrome(s, l, r):
        while r > l:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

    l = 0
    r = len(s) - 1
    while r > l:
        if s[l] != s[r]:
            return check_palindrome(s, l, r-1) or check_palindrome(s, l+1, r)
        l += 1
        r -= 1
    return True



s = "aba"
#Output: true
result = valid_palindrome(s)
print("result: " + str(result))

s = "abca"
#Output: true
result = valid_palindrome(s)
print("result: " + str(result))

s = "abc"
#Output: false
result = valid_palindrome(s)
print("result: " + str(result))
