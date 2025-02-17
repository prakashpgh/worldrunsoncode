'''
greedy approach does not always give the optimal solution

recursive approach...
    top down..
    go thru the coins, and do a recurse..

    https://www.geeksforgeeks.org/coin-change-dp-7/

    Idea here is you have 2 choices
        1) take the coin at nth index => sum will reduce & n will be same 
        Or
        2) dont take the coin => sum not reduced, coins reduced

        take the min of the 2 cases

        base cases: sum = 0, return 0,.
            sum < 0 or n <= 0 => return max

        --
        memo will be sum & num
        
'''
def minimum_coins_recursion_topdown(nums, target):
    nums.sort()
    N = len(nums)
    dp = {0:0}

    def dp_func(amount):
        if amount in dp:
            return dp[amount]
        mi = float('inf')
        #go thru the coins
        for c in nums:
            remaining = amount - c
            if remaining < 0:
                break
            mi = min(mi, 1 + dp_func(remaining))
        dp[amount] = mi
        return mi        

    result = dp_func(target)
    if result == float('inf'):
        return -1
    else:
        return result
   

'''

'''
def minimum_coins(coins, target):
    #sort if firts
    coins.sort()
    memo = [0] * (target+1)
    N = len(coins)
    #fill from 1 to the target.
    for i in range(1,target+1):
        min1=float('inf')
        #for each go thru the coins array
        for j in range(N):
            remaining = i - coins[j]
            if remaining < 0:
                #not possible to make, we ignore the remainign coins as they are larger
                continue
            min1 = min(min1, 1+memo[remaining])
        memo[i] = min1

    result = memo[target]
    if result < float('inf'):
        return result
    else:
        return -1


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

