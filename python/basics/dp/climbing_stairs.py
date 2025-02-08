#https://leetcode.com/problems/climbing-stairs/description/


def climbing_stairs_iterative(n):
    if n==1:
        return 1
    if n==2:
        return 2
    a = 1
    b = 2
    for i in range(2,n):
        result = a + b
        a = b 
        b = result
    return b


def climbing_stairs_recurring(n):
    result = 0
    memo = {0:0,1:1,2:2}
    def stairs(n):
        if n==1:
            return 1
        if n==2:
            return 2
        if n in memo:
            return memo[n]
        st = stairs(n-1) + stairs(n-2)
        memo[n] = st
        return memo[n]
    return stairs(n)


n = 2
result =climbing_stairs_recurring(n)
print("result: " + str(result))
'''
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
'''
result =climbing_stairs_iterative(n)
print("result-iterative: " + str(result))




n = 3
result =climbing_stairs_recurring(n)
print("result: " + str(result))
'''
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
'''
result =climbing_stairs_iterative(n)
print("result-iterative: " + str(result))
