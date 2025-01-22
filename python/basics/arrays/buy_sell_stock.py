

#O(n**2)
#brute force
def buy_sell_stock(prices: list[int]):
    max_profit = 0
    buy_price = 0
    sell_price = 0
    for i in range(len(prices)):
        for j in range(i+1, len(prices)):
            buy = prices[i]                
            sell = prices[j]
            profit = sell -buy   
            if(profit > max_profit):
                max_profit = profit
                buy_price = buy
                sell_price = sell
    print("buy_sell_stock => buy: {}  sell: {}  profit: {}", buy_price, sell_price, max_profit)
    return max_profit

prices = [7,1,5,3,6,4]
buy_sell_stock(prices)



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
                print("buy_sell_stock_n buy: {}  sell: {}  profit: {}", buy_price, sell_price, max_profit)
    return max_profit

prices = [7,1,5,3,6,4]
profit = buy_sell_stock_n(prices)
