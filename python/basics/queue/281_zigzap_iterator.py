'''
https://leetcode.com/problems/zigzag-iterator
#todo

use Q
    add the array and the current index of array to Q.

while Q:
    (array, index) = popleft()
    append to Q with index ++
'''

class ZigzagIterator:
    def __init__(self, v1: list[int], v2: list[int]):
        pass

    def next(self) -> int:
        pass

    def hasNext(self) -> bool:
        pass

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())