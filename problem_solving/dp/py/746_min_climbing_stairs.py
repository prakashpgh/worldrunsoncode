#https://leetcode.com/problems/climbing-stairs/description/
'''
https://www.geeksforgeeks.org/minimum-cost-to-reach-the-top-of-the-floor-by-climbing-stairs/
    ith floor can be reached from i-1 or i-2 floors
    min of cost from i-1 and i-2 floors
    
'''
def min_climbing_stairs(nums):
    N=len(nums)
    if N<2:
        return 0
    #need N as we want the upper floor..
    memo =[0]*(N+1)
    memo[0]=0
    memo[1]=0
    for i in range(2, N+1):
        memo[i]=min(memo[i-1]+nums[i-1], memo[i-2]+nums[i-2]) 
    return memo[N]  #need N as we want the upper floor..


def min_climbing_stairs_recursive(nums):
    N=len(nums)
    memo = {}
    memo[0] = 0
    memo[1] = 0

    def dp(i):    
        if i<2:
            return 0
        if i in memo:
            return memo[i]
        m = min(dp(i-1) + nums[i-1], dp(i-2) + nums[i-2])
        memo[i] = m
        return m

    return dp(N)


cost = [10,15,5,30,4,4,10]
result = min_climbing_stairs(cost)
print("result: " + str(result))
result = min_climbing_stairs_recursive(cost)
print("result-recur: " + str(result))


cost = [10,15,20]
'''
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
'''
result = min_climbing_stairs(cost)
print("result: " + str(result))
result = min_climbing_stairs_recursive(cost)
print("result-recur: " + str(result))


cost = [1,100,1,1,1,100,1,1,100,1]
'''
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
'''
result = min_climbing_stairs(cost)
print("result: " + str(result))
result = min_climbing_stairs_recursive(cost)
print("result-recur: " + str(result))
