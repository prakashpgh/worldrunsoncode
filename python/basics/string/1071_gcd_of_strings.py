'''
https://leetcode.com/problems/greatest-common-divisor-of-strings/

1) check concat by order..
2) gcd of len of strings.

t:O(m+n) => compare string conat (m+n), gcd (log mn ) 

s:O(m+n) => string comparison


Alternative approach:

    find the shorter string 
    iterate starting with short string len starting with full string {
        check if its gcd..
            gcdBase. the lengths should be multiples
            gcdBase*factor = original string
    }
    
'''

def gcd(m, n):
    divisor = min(m,n)
    dividend = max(m,n)
    remain = 1
    while remain != 0:
        remain = dividend % divisor
        if remain == 0:
            break
        dividend = divisor
        divisor = remain
        #print("r: " + str(remain) + "r: " + str(divisor) + "r: " + str(dividend))
    return divisor

def gcd_of_strings(s1: str, s2: str) -> str:
    if s1+s2 != s2+s1:
        return ""
    max_length=gcd(len(s1), len(s2))
    return s1[:max_length]


result = gcd(12, 16)
print("result= " + str(result))


str1 = "ABCABC"
str2 = "ABC"
#Output: "ABC"
result = gcd_of_strings(str1, str2)
print("result= " + str(result))


str1 = "ABABAB"
str2 = "ABAB"
#Output: "AB"
result = gcd_of_strings(str1, str2)
print("result= " + result)


str1 = "LEET"
str2 = "CODE"
#Output: ""
result = gcd_of_strings(str1, str2)
print("result= " + result)
