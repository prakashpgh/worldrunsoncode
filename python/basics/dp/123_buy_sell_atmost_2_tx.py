'''
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

#####
Approach I:
        find the profit for 1st tx... use the remaining of the array to find the 2nd tx.

    iterate the prices array
    find the lowest price..
    if price > lowest price,
        find the profit.  this is your 1st tx.
        now use the remaining array to find the 2nd tx.
        use that to get the total profit.
    keep doing this
    O(N**2)

Approach 2)
    https://www.youtube.com/watch?v=q4Vr307dOzs
    first pass l->r   calc. profit in an array
    second r->l calc profit. with max sell price
    get max sum from the 2 arrays...
    O(3*N) -> three times loop

Approach 3)
    https://www.youtube.com/watch?v=q4Vr307dOzs
    use effective buy price

    Buy_1 ~ min
    Profit_1 ~ max
    EffectiveBuy_2 ~ min = cost_2 - profit_1
    Profit_2 ~ max

    O(N)
'''
#todo
def buy_sell_atmost_2_2N_approach():
    profit = 0

    return profit



def buy_sell_atmost_effective_buy_price_approach(prices: list[int]):
    buy_price = float('inf')
    profit_1 = float('-inf')
    eff_buy_price = float('inf')
    profit_2 = float('-inf')

    for i in range(len(prices)):
        buy_price = min(buy_price, prices[i])
        profit_1 = max(profit_1, prices[i]-buy_price)
        eff_buy_price = min(eff_buy_price, prices[i] - profit_1)
        profit_2 = max(profit_2, prices[i]-eff_buy_price)
    return profit_2



prices = [3,3,5,0,0,3,1,4]
#Output: 6
result = buy_sell_atmost_effective_buy_price_approach(prices)
print("result: " + str(result))


prices = [1,2,3,4,5]
#Output: 4
result = buy_sell_atmost_effective_buy_price_approach(prices)
print("result: " + str(result))


prices = [7,6,4,3,1]
#Output: 0
result = buy_sell_atmost_effective_buy_price_approach(prices)
print("result: " + str(result))


