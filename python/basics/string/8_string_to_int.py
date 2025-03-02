'''
https://leetcode.com/problems/string-to-integer-atoi/

here the main thing are the validations..
-ve numbers

overflow

leading zeros

spaces => ignore leading space... any spaces after numbe starts.. ignore the part after the space starts.

#meta
'''

def string_to_int(s: str) -> int:
    negative = False
    number_started = False
    number = 0
    N = len(s)
    i = 0
    while i < len(s) and not s[i].isdigit():
        if s[i] == " ":    
            i += 1
        elif s[i] == "-":
            negative = True
            i += 1
            break
        elif s[i] == "+":
            i += 1
            break
        else:
            return 0

    while i < N and s[i]=="0":
        i += 1

    for j in range(i, len(s)):
        if not s[j].isdigit():
            break
        number = number*10 + int(s[j])

    if negative:
        number = -number
        if number < pow(-2, 31):
            number = pow(-2, 31)
    elif number > pow(2, 31) -1:
        number = pow(2, 31) -1 
    return number



s = "42"
#42
result = string_to_int(s)
print("result: " + s + " = " + str(result))


s = "042"
#42
result = string_to_int(s)
print("result: " + s + " = " + str(result))


s = "-042"
#42
result = string_to_int(s)
print("result: " + s + " = " + str(result))



s = " -042"
result = string_to_int(s)
print("result: " + s + " = " + str(result))


s = "1337c0d3"
Output: 1337
result = string_to_int(s)
print("result: " + s + " = " + str(result))


s = "0-1"
Output: 0
result = string_to_int(s)
print("result: " + s + " = " + str(result))


s = "words and 987"
Output: 0
result = string_to_int(s)
print("result: " + s + " = " + str(result))
