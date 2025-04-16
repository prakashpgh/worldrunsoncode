'''
https://leetcode.com/problems/reverse-bits/

the lsb is masked & shifted pow units to left & added to the result
input is shifted right till it becomes 0
'''


def reverseBits(n: int) -> int:
    res = 0
    pow = 31
    while n:
        res += (n & 1) << pow
        pow -= 1
        n >>=  1
    return res


n = int("00000010100101000001111010011100", 2)
result = reverseBits(n)
print("result: " + str(result))
#964176192 


n = 11111111111111111111111111111101
#3221225471 