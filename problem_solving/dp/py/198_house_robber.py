
'''
bottom up... fill the dp array
time: O(n)
space: O(n)
https://leetcode.com/problems/house-robber/

https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

the robber cannot rob the adjacent houses
    so choice is i-1th house OR i-2  && ith
    max(total till i-2  + value of i   Or   value of i-1)
'''
def house_robber(nums: list[int]) -> int:
    N = len(nums)
    dp = [0]*N
    if N==1:
        return nums[0]
    if N==2:
        return max(nums[0],nums[1])
    dp[0]=nums[0]
    dp[1]= max(nums[0],nums[1])
    for i in range(2, N): # ==> made a mistakehere.
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]) # => this is the algo
    
    return dp[N-1]

'''
    recursive.. basecriteria
'''
def house_robber_recursive(nums: list[int]) -> int:
    N = len(nums)
    memo = {}

    def dp(i):
        if i >= len(nums):
            return 0
        if i in memo:
            return memo[i]
        else:
            m = max(dp(i+1), dp(i+2) + nums[i]) # => this is the algo
            memo[i] = m
            return m
    
    return dp(0)

nums = [1,2,3,1]
#Output: 4
#Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
#Total amount you can rob = 1 + 3 = 4.
result = house_robber(nums)
print("result: " + str(result))
result = house_robber_recursive(nums)
print("result-recur: " + str(result))



nums = [2,7,9,3,1]
#Output: 12
#Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
#Total amount you can rob = 2 + 9 + 1 = 12.
result = house_robber(nums)
print("result: " + str(result))

