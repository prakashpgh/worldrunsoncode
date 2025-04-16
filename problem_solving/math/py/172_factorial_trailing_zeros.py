'''
https://leetcode.com/problems/factorial-trailing-zeroes/
Approach 1:
    calc the factorial
    find the trailing zeros

Approach 2:
    iterate 1.. n
    if n ends with 5, keep dividing by 5s.. basically count all factors of 5
'''

def factorial_trailing_zeros(n):
    fact = 1
    for i in range(1, n+1):
        fact *= i
    zeros = 0
    while fact:
        r = fact % 10
        zeros += (r == 0)
        fact /= 10
    return zeros


def factorial_trailing_zeros_find_5s(n):
    zeros = 0
    for i in range(1, n+1):
        current = i
        while current % 5 == 0: #made a mistake here
            r = current % 5
            zeros += (r==0)
            current /= 5
    return zeros


n = 7743
#Output: 0
#result = factorial_trailing_zeros(n)
#print("result: " + str(n) + "  =>  " + str(result))

result = factorial_trailing_zeros_find_5s(n)
print("result-5s: " + str(n) + "  =>  " + str(result))



n = 6
#Output: 0
result = factorial_trailing_zeros(n)
print("result: " + str(n) + "  =>  " + str(result))

result = factorial_trailing_zeros_find_5s(n)
print("result-5s: " + str(n) + "  =>  " + str(result))


n = 3
#Output: 0
result = factorial_trailing_zeros(n)
print("result: " + str(result))

result = factorial_trailing_zeros_find_5s(n)
print("result-5s: " + str(result))



n = 5
#Output: 1
#Explanation: 5! = 120, one trailing zero.
result = factorial_trailing_zeros(n)
print("result: " + str(result))

result = factorial_trailing_zeros_find_5s(n)
print("result-5s: " + str(result))


n = 0
#Output: 0
result = factorial_trailing_zeros(n)
print("result: " + str(result))

result = factorial_trailing_zeros_find_5s(n)
print("result-5s: " + str(result))

