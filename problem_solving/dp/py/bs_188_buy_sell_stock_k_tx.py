'''
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

atmost k transactions..

    options on ith day, 
        no action
        sell if you have the stock
        buy if you dont have the stock

    prices
    n_transactions
    state

    find max profit
'''

'''
https://www.youtube.com/watch?v=qSGdZfkQ8C8

    k=0     => no profit
    day = 0 => no profit

no transactions => profit from previous day
        M= profit from previous day = dp[i][j-1]  i=transactions, j=days
        N=profit from today's tx.
        dp[i][j] = max(M, N)

        For N, we will be selling & the buy should have occured on any of the days 0...j-1,   i-1 tx should have been completed
            max( price[j] - price[i] + dp[i-1][x])
        profit on jth day = max( all possible profits )
                A = dp[i-1][x] = profit till day x because of i-1 transactions.  Note Buy + Sell = 1 transaction
                B = p[j] -p[x] = profit because of ith transaction
                total profit = A + B
                take max of (this for all the days.., No transactions  )
'''

#t:O(kN)
#s:O(kN)
def max_profit_iterative_effective_buy_price( k:int, prices:list[int]):
    N=len(prices)
    dp = [[0]*(N) for i in range(k+1)]
    print("dp: " + str(dp))
    if N < 2:
        return 0 #since we have atmost 1 price
    #if k < 1:
    #    return 0 #we have no transaction
    for i in range(1, k+1):
        effective_buy_price = prices[0]
        for j in range(1,N):
            #max of no-tx & sell
            #dp[i][j-1] = profit with no tx
            #helper(i, j, prices, dp) = profit with tx
            #effective buy prices = price - profit = prices[j]-dp[k-1][j]
            #dp[i-1][j] = profits from all previous transactions
            dp[i][j] = max(dp[i][j-1], prices[j] - effective_buy_price)  
            effective_buy_price = min(effective_buy_price, prices[j] - dp[i-1][j])
    print("dp: " + str(dp))
    return dp[k][N-1]


def max_profit_iterative( k:int, prices:list[int]):
    N=len(prices)
    dp = [[0]*(N+1) for i in range(k+1)]
    print("dp: " + str(dp))
    if N < 2:
        return 0 #since we have atmost 1 price
    if k < 1:
        return 0 #we have no transaction
    for i in range(1, k+1):
        for j in range(1,N+1):
            #max of no-tx & sell
            #dp[i][j-1] = profit with no tx
            #helper(i, j, prices, dp) = profit with tx
            #max of previous day profit, today's profit
            #dp[i][j-1] => previous day profit  #helper(i, j, prices, dp) => today' profit with transacations
            dp[i][j] = max(dp[i][j-1], helper(i, j, prices, dp))
    return dp[k][N]

# P - SP - BP
#this will give the max profit for selling.
#p[j] - p[x] + dp[k-1][x]  => assumes we are selling on jth day, with buy on xth day.  price diff j & i, max profit on xth day with k-1 tx
def helper(tx, p, prices, dp):
    val = 0
    for i in range(p):
        #compare the profits of buy on ith and sell on pth day + profit on ith day with tx-1
        #dp[tx-1][i] => profits due to tx-1 tx, till ith day,  prices[p] - prices[i] = profit due buy buy on ith and sell on pth day
        val = max(val, prices[p] - prices[i] + dp[tx-1][i])
    return val


prices = [0,1,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000,0,1000]
k=100
#result = max_profit_iterative(k, prices)
#print("result-iter: " + str(result))


result = max_profit_iterative_effective_buy_price(k, prices)
print("result-iter-ebp: " + str(result))

#-----------------------------

k = 2
prices = [2,4,1]
#Output: 2
#Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

result = max_profit_iterative(k, prices)
print("result-iter: " + str(result))

result = max_profit_iterative_effective_buy_price(k, prices)
print("result-iter-ebp: " + str(result))

#-----------------------------


k = 2
prices = [3,2,6,5,0,3]
#Output: 7

result = max_profit_iterative(k, prices)
print("result-iter: " + str(result))

result = max_profit_iterative_effective_buy_price(k, prices)
print("result-iter-ebp: " + str(result))
