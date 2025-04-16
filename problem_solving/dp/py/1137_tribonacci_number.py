'''
https://leetcode.com/problems/n-th-tribonacci-number
similar to fibonacii..
t: O(N)
s: O(1)
'''

def tribonacci(n: int) -> int:
    if n == 0:
        return 0
    elif n == 1:
        return 1
    elif n == 2:
        return 1
    tn0 = 0
    tn1 = 1
    tn2 = 1
    tn3 = 0

    for i in range(3, n+1):
        tn3 = tn2 + tn1 + tn0
        tn0 = tn1
        tn1 = tn2
        tn2 = tn3
    return tn3



n = 4
#Output: 4
result = tribonacci(n)
print("result: " + str(result))

n = 25
#Output: 1389537
result = tribonacci(n)
print("result: " + str(result))
