'''
https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
'''

'''
    lets try that rod is broken into [i + (len-i)]  => 
    the price is p[i] + recursive(len - i, prices)
'''
def cutting_rod_price(length, prices):
    if length <= 0:
        return 0
    max_price = float('-inf')
    for i in range(length):
        price = prices[i] + cutting_rod_price(length-i-1, prices)
        max_price = max(max_price, price)
    return max_price

'''
length is the changing parameter
memo is the array of length
'''
def cutting_rod_price_memo(length, prices):
    memo = [-1] * length
    memo[0] = 0
    def dp(length, prices):
        if memo[length-1] != -1:
            return memo[length-1]
        if length <= 0:
            return 0
        max_price = float('-inf')
        for i in range(length):
            price = prices[i] + cutting_rod_price(length-i-1, prices)
            max_price = max(max_price, price)
            memo[length-1] = max_price  
        return max_price
    return dp(length, prices)

'''
iterative - bottom up
dp[0] = 0   we need N+1 array size here

'''
def cut_rod_bottom_up(prices):
    N = len(prices)
    dp = [0] * ( N + 1)
    for i in range(1, N+1):
        for j in range(1, i+1):
            dp[i] = max(dp[i], prices[j-1] + dp[i-j])
    return dp[N]



prices =  [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
#Explanation:  The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
result = cutting_rod_price(len(prices), prices)
print("length: " + str(result))

result = cutting_rod_price_memo(len(prices), prices)
print("length: " + str(result))


result = cut_rod_bottom_up(prices)
print("length: " + str(result))


prices =  [3, 5, 8, 9, 10, 17, 17, 20]
#Output : 24
#Explanation : The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1]= 8*3 = 24.
result = cutting_rod_price(len(prices), prices)
print("length: " + str(result))


prices =  [3]
#Output : 3
result = cutting_rod_price(len(prices), prices)
print("length: " + str(result))
