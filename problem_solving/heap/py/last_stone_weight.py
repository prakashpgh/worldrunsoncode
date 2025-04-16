#https://leetcode.com/problemset/?page=1&search=1046
'''

'''
import heapq

def lastStoneWeight(stones: list[int]):
    N = len(stones)
    #to support max heap
    for i in range(N):
        stones[i] = -stones[i]

    heapq.heapify(stones)
    while len(stones) > 1:
        i = heapq.heappop(stones)
        j = heapq.heappop(stones)
        if i != j:
            heapq.heappush(stones, i-j)
    if len(stones)==1:
        return -stones[0]
    return -1    



#Input: 
stones = [2,7,4,1,8,1]
#1
result = lastStoneWeight(stones)
print("result: " + str(result))

stones = [1]
#Output: 1
result = lastStoneWeight(stones)
print("result: " + str(result))


stones = [2,4,8]
#Output: 1
result = lastStoneWeight(stones)
print("result: " + str(result))
