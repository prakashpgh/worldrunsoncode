'''
https://leetcode.com/problems/online-stock-span/
monotonic decreasing stack..
store the price and the span
'''

class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        span = 1
        #print("price: " + str(price))
        #print("stack: " + str(self.stack))
        while self.stack and price >= self.stack[-1][0]:
            #print("popping.." + str(len(self.stack)))
            [price1, span1] = self.stack.pop()
            #print("after popping.." + str(len(self.stack)))
            span += span1
        self.stack.append([price, span])
        #print(self.stack)
        return span


# Your StockSpanner object will be instantiated and called as such:
stockSpanner = StockSpanner()
result = stockSpanner.next(100)
print("result: " + str(result))
result = stockSpanner.next(80);  # return 1
print("result: " + str(result))
result = stockSpanner.next(60);  #// return 1
print("result: " + str(result))
result = stockSpanner.next(70);  #// return 2
print("result: " + str(result))
result = stockSpanner.next(60);  #// return 1
print("result: " + str(result))
result = stockSpanner.next(75);  #// return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
print("result: " + str(result))
result = stockSpanner.next(85);  #// return 6
print("result: " + str(result))
