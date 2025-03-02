'''
https://leetcode.com/problems/sqrtx/description/
Approach:
    use binary search.. iterate from 1..n.  
    binary search ... test if its square root..
'''

def square_root(num):
    if num < 2:
        return num

    l = 2
    r = num // 2
    while l <= r:
        m = l + (r-l)//2
        sq = m * m
        if sq == num:
            return m
        elif sq > num:  #mistake there was a typo here
            r = m -1
        else:
            l = m + 1
    return r

x = 8
result = square_root(x)
print("square root of : " + str(x) + "      " + str(result))


x = 2
result = square_root(x)
print("square root of : " + str(x) + "      " + str(result))


x = 0
result = square_root(x)
print("square root of : " + str(x) + "      " + str(result))


x = 4
result = square_root(x)
print("square root of : " + str(x) + "      " + str(result))

x = 225
result = square_root(x)
print("square root of : " + str(x) + "      " + str(result))



    