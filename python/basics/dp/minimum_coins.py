'''
greedy approach does not always give the optimal solution

recursive approach...
    top down..
    go thru the coins, and do a recurse..

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



coins = [186, 419, 83, 408]
amount = 6249
result = minimum_coins(coins, amount)
print("result:" + str(coins)+ " = " + str(result))
result = minimum_coins_recursion_topdown(coins, amount)
print("result-recur:" + str(coins)+ " = " + str(result))

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

