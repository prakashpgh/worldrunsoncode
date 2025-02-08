'''
https://leetcode.com/problems/sqrtx/description/
'''

def square_root(num):
    l = 1
    r = num
    while r >= l:
        m = (r+l)//2
        sq = m * m
        if sq == num:
            return m
        elif sq > m:
            r = r -1
        else:
            l = l + 1
    return l


x = 4
result = square_root(x)
print("square root: " + str(result))

x = 225
result = square_root(x)
print("square root: " + str(result))


x = 8
result = square_root(x)
print("square root: " + str(result))

    