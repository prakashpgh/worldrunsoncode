'''
https://leetcode.com/problems/add-binary/description/?envType=study-plan-v2&envId=top-interview-150

Idea:  add 2 numbers,  
        without carry = ^
        carry   & << 1
        continue this till y =0

'''

def add_binary(a:str, b:str):
    x = int(a, 2)
    y = int(b, 2)
    while y:
        without_carry = x ^ y
        carry = (x & y) << 1
        x = without_carry
        y = carry
    return bin(x)[2:]



        
a = "11"
b = "1"
#Output: "100"
result = add_binary(a, b)
print("result:" + result)


a = "1010"
b = "1011"
#Output: "10101"
result = add_binary(a, b)
print("result:" + result)
 