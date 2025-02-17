'''
#https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150
brute force  O(n**2)

iterate the prices.  update the min. price.
for each tick,find the profix and update the max profit

'''
#O(n)
#space O(1)
'''
buy at the lowest price
sell at the highest price
keep a note of the max profit
'''
def buy_sell_stock_n(prices: list[int]):
    buy_price = prices[0]
    sell_price = 0
    max_profit = 0
    for price in prices:
        if price < buy_price:
            buy_price = price
        elif price > buy_price:
            profit = price - buy_price
            if profit > max_profit:
                max_profit = profit
                sell_price = price
                #print("buy_sell_stock_n buy: {}  sell: {}  profit: {}", buy_price, sell_price, max_profit)
    return max_profit

prices = [7,1,5,3,6,4]
profit = buy_sell_stock_n(prices)
print("profit: " + str(profit))

prices = [7,6,4,3,1]
profit = buy_sell_stock_n(prices)
print("profit: " + str(profit))