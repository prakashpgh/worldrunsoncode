'''
https://leetcode.com/problems/coin-change/
greedy approach does not always give the optimal solution

Approach I: recursive
            you need amount A
            recur(amount) {
            exit criteria

                    0 or -ve
            Choices:
                for() => coins {
                    min = min(min_needed, 1 + recur(amount-coin))
                }
            }
            Parameters: amount

Approach II:
    find the coins needed for 0, 1 etc.. and build from there.

    dp array fill to float('inf')
    dp[0] = 0
        for for all dp[1] .. dp[target]
        for all coins {
            dp[i] = min(dp[i], dp[i-coin] + 1)
        }
'''
def minimum_coins_recursion_topdown(nums, target):
    nums.sort()
    N = len(nums)
    dp = {0:0}

    def dp_func(amount):
        if amount in dp:
            return dp[amount]
        mi = float('inf')
        if amount < 0:
            return float('inf')

        #go thru the coins
        for c in nums:
            remaining = amount - c
            mi = min(mi, 1 + dp_func(remaining))
        dp[amount] = mi
        return mi        

    result = dp_func(target)
    if result == float('inf'):
        return -1
    else:
        return result
    

''' 
iterative dp method
'''
def minimum_coins(coins, target):
    #sort 
    coins.sort()
    memo = [float('inf')] * (target+1)
    N = len(coins)
    memo[0] = 0
    #fill from 1 to the target.
    for i in range(1,target+1):
        #for each go thru the coins array
        for j in range(N):
            memo[i] = min(memo[i], memo[i - coins[j]] + 1)

    if memo[target] == float('inf'):
        return -1
    else:
        return memo[target]


def min_coins_g4g_recur(coins:list[int], sum:int) -> int:
    result = -1
    N=len(coins)
    def dp(sum, n):
        if sum == 0:
            return 0
        if sum < 0 or n <= 0:
            return float('inf')
        take = 1 + dp(sum-coins[n-1], n)
        not_take = dp(sum, n-1)
        return min(take, not_take) 
    return dp(sum, N)


coins = [186, 419, 83, 408]
amount = 6249
result = minimum_coins(coins, amount)
print("result:" + str(coins)+ " = " + str(result))
result = minimum_coins_recursion_topdown(coins, amount)
print("result-recur-g4g-topdown:" + str(coins)+ " = " + str(result))

result = min_coins_g4g_recur(coins, amount)
print("result-g4g-topdown:" + str(coins)+ " = " + str(result))


#
# exit(0)

coins = [1,4,5]
amount = 12
result = minimum_coins(coins, amount)
print("result:" + str(coins)+ " = " + str(result))
#Output: 3
result = minimum_coins_recursion_topdown(coins, amount)
print("result-recur:" + str(coins)+ " = " + str(result))


coins = [1,2,5]
amount = 11
#Output: 3
#Explanation: 11 = 5 + 5 + 1
result = minimum_coins(coins, amount)
print("result:" + str(coins)+ " = " + str(result))
result = minimum_coins_recursion_topdown(coins, amount)
print("result-recur:" + str(coins)+ " = " + str(result))


coins = [2]
amount = 3
#Output: -1
result = minimum_coins(coins, amount)
print("result:" + str(coins)+ " = " + str(result))
result = minimum_coins_recursion_topdown(coins, amount)
print("result-recur:" + str(coins)+ " = " + str(result))


coins = [1]
amount = 0
#Output: 0
result = minimum_coins(coins, amount)
print("result:" + str(coins)+ " = " + str(result))
result = minimum_coins_recursion_topdown(coins, amount)
print("result-recur:" + str(coins)+ " = " + str(result))

