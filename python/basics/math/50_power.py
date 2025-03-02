'''
https://leetcode.com/problems/powx-n/

x**n = (x**2)**(n/2)

x**n = x. x**(n-1) = x. (x**2)**((n-1)/2)

#interesting if you want O(logN)
'''

def power(x:int,n:int):
    if n==0:
        return 1
    if n < 0:
        return 1/power(x, -n)       #mistake need to take care of -ve power
    
    if n%2==0:
        return power((x*x), n/2)
    else:
        return x * power((x*x), (n-1)/2)



x = 2.00000
n = 10
#Output: 1024.00000
result = power(x, n)
print("result: " + str(result))

x = 2.10000
n = 3
#output: 9.26100
result = power(x, n)
print("result: " + str(result))



x = 2.00000
n = -2
#Output: 0.25000
result = power(x, n)
print("result: " + str(result))
