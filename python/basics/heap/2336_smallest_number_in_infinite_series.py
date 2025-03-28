'''
https://leetcode.com/problems/smallest-number-in-infinite-set/
2336_smallest_number_in_infinite_series.py

use of min_heap
store +ve integers thru infinity.
You are not actually storing it...
    if some one pops, then check if in heap,else use the current pointer

'''

class SmallestInfiniteSet:

    def __init__(self):
        self.min_heap = []
        self.current = 1

    def popSmallest(self) -> int:
        if self.min_heap:
            return heappop(self.min_heap)
        min = self.current
        self.current += 1
        return min

    def addBack(self, num: int) -> None:
        if num < self.current and num not in self.min_heap:
            heapq.heappush(self.min_heap, num)
