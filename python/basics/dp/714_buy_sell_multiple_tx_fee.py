'''
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
https://www.youtube.com/watch?v=Ew_R-ZfhPEc

'''

def buy_sell_multiple_tx_fee(prices: list[int], fee) -> int:
    N=len(prices)
    if N == 0:
        return 0
    profit = 0
    effective_buy_price = prices[0]

    for i in range(1, N):
        profit = max(profit, prices[i] - effective_buy_price - fee)
        effective_buy_price = min( effective_buy_price, prices[i] - profit)
    return profit

prices = [1,3,2,8,4,9]
fee = 2
#Output: 8
result = buy_sell_multiple_tx_fee(prices, fee)
print("result = " + str(result))


prices = [1,3,7,5,10,3]
fee = 3
#Output: 6
result = buy_sell_multiple_tx_fee(prices, fee)
print("result = " + str(result))
