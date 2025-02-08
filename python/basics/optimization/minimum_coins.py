#https://www.youtube.com/watch?v=KTaEeTWRwgg
#todo
#https://www.youtube.com/watch?v=koE9ly1CFDc
#smallest number of coin
#greedy does not give the right answer

def minimum_coin_change(coins:list[int], target:int)-> int:
    result = float('inf')

    coins.sort()
    memo = {0:0}
    def dp(amount):
        #memoization
        if amount in memo:
            return memo[amount]
        
        n_coins = float('inf')
        #iterate thru the coins..
        for coin in coins:
            diff = amount - coin
            #not possible any more since coins are sorted
            if diff < 0:
                break
            n_coins = min(n_coins, 1 + dp( diff))    
        
        memo[amount]=n_coins
        return n_coins
    
    n_coins = dp(target)
    if n_coins == float('inf'):
        return -1
    return n_coins

    return result



coins = [1,2,5]
amount = 11
result = minimum_coin_change(coins, amount)
print("result: " + str(result))
#3

coins = [2]
amount = 3
result = minimum_coin_change(coins, amount)
print("result: " + str(result))
#-1

coins = [1]
amount = 0
result = minimum_coin_change(coins, amount)
print("result: " + str(result))
#0

coins = [1,4,5]
amount = 12
result = minimum_coin_change(coins, amount)
print("result: " + str(result))
