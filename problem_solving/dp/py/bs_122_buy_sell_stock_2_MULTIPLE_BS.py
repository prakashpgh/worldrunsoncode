'''
#https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

repeat 1 & 2 using while loop
    1) buy at the lowest .. using while
    2) sell at highest using while

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


def buy_sell_stock_effective_buy_price(prices: list[int]):
    N=len(prices)
    profit = 0
    effective_buy_price = prices[0]

    for i in range(1, N):
        profit = max(profit, prices[i] - effective_buy_price)
        effective_buy_price = min(effective_buy_price, prices[i] - profit)
    return profit




prices = [7,6,4,1,5,8,3,6,4]
profit = buy_sell_stock(prices)
print("profit: " + str(profit))
profit = buy_sell_stock_effective_buy_price(prices)
print("profit-effective: " + str(profit))

#10


prices = [7,1,5,3,6,4]
#7
profit = buy_sell_stock(prices)
print("profit: " + str(profit))
profit = buy_sell_stock_effective_buy_price(prices)
print("profit-effective: " + str(profit))
#-------------------------------------

prices = [7,6,4,3,1]
#0
profit = buy_sell_stock(prices)
print("profit: " + str(profit))
profit = buy_sell_stock_effective_buy_price(prices)
print("profit-effective: " + str(profit))


prices = [1,2,3,4,5]
#4
profit = buy_sell_stock(prices)
print("profit: " + str(profit))
profit = buy_sell_stock_effective_buy_price(prices)
print("profit-effective: " + str(profit))


prices = [3,3,5,0,0,3,1,4]
#Output: 6
profit = buy_sell_stock(prices)
print("profit: " + str(profit))
profit = buy_sell_stock_effective_buy_price(prices)
print("profit-effective: " + str(profit))
