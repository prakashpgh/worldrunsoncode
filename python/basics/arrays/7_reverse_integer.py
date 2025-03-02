'''
https://leetcode.com/problems/reverse-integer/
#mistake => check for the negative number
    check for overflow

#meta
'''


def reverse_integer(x:int):
    neg = False
    if x < 0:
        neg = True
    x = abs(x)
    ans = 0
    while x:
        r = x % 10
        x = x // 10     #MISTAKE
        ans = 10 * ans + r 
        if ans > 2**31 - 1:     #overflow check
            return 0
    if neg:
        ans = -ans
    return ans



x = 123
ans = reverse_integer(x)
print("x=" + str(x) + " reverse: " + str(ans))



x = -123
ans = reverse_integer(x)
print("x=" + str(x) + " reverse: " + str(ans))


