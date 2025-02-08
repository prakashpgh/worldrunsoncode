'''
#https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

'''
def buy_sell_stock(prices: list[int]):
    N=len(prices)
    i = 0
    buy = 0
    profit = 0
    while i < N-1:
        while i < N-1 and prices[i] >= prices[i+1]:
            i += 1
        buy = prices[i]
        #print("buy: " + str(buy))
        #sell
        while i < N-1 and prices[i] <= prices[i+1]:
            i += 1
        sell = prices[i]
        #print("sell: " + str(sell))
        profit += sell - buy
        #print("profit: " + str(profit))
    return profit

prices = [7,6,4,1,5,8,3,6,4]
profit = buy_sell_stock(prices)
print("profit: " + str(profit))
#10


prices = [7,1,5,3,6,4]
#7
profit = buy_sell_stock(prices)
print("profit: " + str(profit))

prices = [7,6,4,3,1]
#0
profit = buy_sell_stock(prices)
print("profit: " + str(profit))


prices = [1,2,3,4,5]
#4
profit = buy_sell_stock(prices)
print("profit: " + str(profit))


