'''
https://leetcode.com/problems/guess-number-higher-or-lower/

classical binary search problem

'''
pick = 9
def guess(n:int):
    if n==6:
        return 0
    elif n > pick:
        return -1
    else:
        return 1


def guess_number_higher_lower(n: int) -> int:
    l = 0
    r = n

    while(l <= r):
        m = l + (r-l)//2
        ans = guess(m)
        if ans == 0: #m == ans:
            return m
        elif ans == -1: #m > pick
            r = m-1
        else:
            l = m+1
    return -1




