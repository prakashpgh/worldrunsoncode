'''
https://www.geeksforgeeks.org/coin-change-dp-7/

Recursion:
    choice:  to use the coin or not use the coin
            if the required sum < 0, return 0
            if the required sum == 0, return 0
'''

def count_ways_coins_gg(coins, sum):
    def dp(sum, n):
        #print("sum: " + str(sum) + " coins: " + str(coins[n-1]))
        if sum == 0:
            #print("sum: " + str(sum) + " coins: " + str(coins[n-1]))
            return 1
        if sum < 0:
            return 0
        if n == 0:
            return 0
        return dp(sum - coins[n-1], n) + dp(sum, n-1)
    return dp(sum, len(coins))


sum = 5
coins = [1, 2, 3]
#Output: 4
result = count_ways_coins_gg(coins, sum)
print("result:" + str(result))