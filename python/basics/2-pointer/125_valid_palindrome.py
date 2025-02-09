#https://leetcode.com/problems/valid-palindrome/
'''
2-pointe technique
isalnum()
'''

def valid_palindrome(s):
    N=len(s)
    l = 0
    r = N-1
    while l < r:
        if not s[l].isalnum():
            l += 1
            continue
        if not s[r].isalnum():
            r -= 1
            continue

        if s[l].lower() != s[r].lower():  #you forgot to change the case !@#$
            return False
        l += 1
        r -= 1
    return True




s = "A man, a plan, a canal: Panama"
result = valid_palindrome(s)
print("result: " + str(result))
#Output: true

s = "race a car"
#Output: false
result = valid_palindrome(s)
print("result: " + str(result))

s = " "
#Output: true
result = valid_palindrome(s)
print("result: " + str(result))
