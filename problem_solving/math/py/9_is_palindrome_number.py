'''
https://leetcode.com/problems/palindrome-number/
'''

def is_palindrome_number(x:int):
    if x == 0:      #mistake - missed the validations here
        return True
    if x < 0 or x %10 == 0:
        return False

    reverse_number = 0
    original_num = x
    i = 0
    while x:
        r = x % 10
        x = x//10
        reverse_number = reverse_number*10  + r     #mistake ... did + instead of x
        i += 1
    print("rev: " + str(original_num) + " => " + str(reverse_number))
    return reverse_number == original_num


x=123
result=is_palindrome_number(x)
print("result:"+ str(x)+" => "+str(result))


x=121
result=is_palindrome_number(x)
print("result:"+ str(x)+" => "+str(result))

x=-121
result=is_palindrome_number(x)
print("result:"+ str(x)+" => "+str(result))

x=10
result=is_palindrome_number(x)
print("result:"+ str(x)+" => "+str(result))




