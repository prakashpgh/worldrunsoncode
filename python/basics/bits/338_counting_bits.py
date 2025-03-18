'''
https://leetcode.com/problems/counting-bits/

ones in x = ones in (x & (x-1)) + 1

x = x & (x-1) => removes the rightmost 1 bit
'''


def count_bits(n: int) -> list[int]:
    a = [0]*(n+1)
    
    def bits(x):
        count = 0
        while x:
            x = x & (x-1)
            count += 1
        return count
    
    for i in range(n+1):
        a[i]=bits(i)
    return a


def count_bits_2(n: int) -> list[int]:
    a = [0]*(n+1)
    for i in range(1,n+1):
        a[i]=a[i & (i-1)] + 1

    return a


n = 2
#Output: [0,1,1]
result = count_bits(n)
print("result: " + str(result))

result = count_bits_2(n)
print("result: " + str(result))
