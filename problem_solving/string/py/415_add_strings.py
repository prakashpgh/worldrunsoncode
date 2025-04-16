'''
https://leetcode.com/problems/add-strings/editorial/

string operations.
ord() function
reverse array.

#meta
'''

def add_strings(a: str, b:str) -> str:
    M=len(a)
    N=len(b)
    i = M-1
    j = N-1
    ans = []
    carry = 0
    while i >= 0 or j >= 0:
        sum = 0
        if i >= 0:
            sum = ord(a[i]) - ord('0')     
        if j >= 0:
            sum += ord(b[j]) - ord('0')
        sum += carry
        val = sum % 10
        ans.append(val)
        carry = sum // 10
        i -= 1
        j -= 1
    if carry:
        ans.append(str(carry))

    return "".join(str(x) for x in ans[::-1])


num1 = "11"
num2 = "123"
#Output: "134"
result = add_strings(num1, num2)
print("result:" + result)


num1 = "456"
num2 = "77"
#Output: "533"
result = add_strings(num1, num2)
print("result:" + result)


num1 = "0"
num2 = "0"
#Output: "0"
result = add_strings(num1, num2)
print("result:" + result)

