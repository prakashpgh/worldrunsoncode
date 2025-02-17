
'''
bottom up... fill the dp array
time: O(n)
space: O(n)

https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

the robber cannot rob the adjacent houses
    so choice is i-1th house OR i-2  && ith
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
    result = 0
    N = len(nums)
    memo = {}
    if N==0:
        return 0
    
    memo[0]=nums[0]
    if N>1:
        memo[1]=max(nums[0], nums[1])

    if N==1:
        return nums[0]
    if N==2:
        return max(nums[0], nums[1])

    def dp(i):
        if i in memo:
            return memo[i]
        else:
            m = max(dp(i-1), dp(i-2) + nums[i]) # => this is the algo
            memo[i] = m
            return m
    
    a = dp(N-1)
    return a

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
