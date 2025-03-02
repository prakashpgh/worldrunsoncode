'''
https://leetcode.com/problems/find-median-from-data-stream/

the idea here is to maintain 2 heaps for the 2 parts of the data..
    lower heap is a max heap.
    upper heap is min heap..

    add => push to lo, pop , push to high, if len high > len low, pop from high, push to low.
    median ... for low, get [0] * -1,   for high, get [0]
'''
import heapq

class MedianFinder:
    def __init__(self):
        self.lo = []
        self.high = []
        
        
    def addNum(self, num: int) -> None:
        heapq.heappush(self.lo, -num)
        if len(self.lo) == 1:
            return  
        val = -(heapq.heappop(self.lo))
        heapq.heappush(self.high, val)
        if len(self.high) > len(self.lo):
            val = heapq.heappop(self.high)
            heapq.heappush(self.lo, -val)
        

    def findMedian(self) -> float:    
        if len(self.lo) == len(self.high):
            val1 = 0
            val2 = 0
            if len(self.lo):
                val1 = -(self.lo[0])    #missed on this
            if len(self.high):
                val2 = self.high[0]  
            return (val1+val2)/2
        else:
            val = 0
            if self.lo:
                val = -(self.lo[0])     #missed on this
            return val
        

        
    
medianFinder = MedianFinder()
medianFinder.addNum(1)    # arr = [1]
medianFinder.addNum(2)    # arr = [1, 2]
result = medianFinder.findMedian() # return 1.5 (i.e., (1 + 2) / 2)
print("result:" + str(result))
medianFinder.addNum(3)    # arr[1, 2, 3]
result = medianFinder.findMedian() # return 2.0
print("result:" + str(result))


#---------
medianFinder = MedianFinder()
medianFinder.addNum(-1)    
result = medianFinder.findMedian() 
print("result:" + str(result))

medianFinder.addNum(-2)    
result = medianFinder.findMedian() 
print("result:" + str(result))

medianFinder.addNum(-3)    
result = medianFinder.findMedian() 
print("result:" + str(result))

medianFinder.addNum(-4)    
result = medianFinder.findMedian() 
print("result:" + str(result))

medianFinder.addNum(-5)
result = medianFinder.findMedian() 
print("result:" + str(result))
