'''
https://leetcode.com/problems/kth-largest-element-in-an-array/description/

O(N) + k * O(log N)
'''
import heapq

#O(N) + k * O(log N)
def findKthLargest(nums: list[int], k:int) -> int:
    #negate array
    N = len(nums)
    for i in range(N):
        nums[i] = -nums[i]
    #make a heap
    heapq.heapify(nums) #O(N)

    i = 0
    while i < k-1:
        #keep popping... check for dups
        heapq.heappop(nums) # O(logN)
        i += 1
    return -heapq.heappop(nums)

#no heapify.. only heap push/pop .. K * log(N)
def findKthLargest_using_min_heap(nums: list[int], k:int) -> int:
    N = len(nums)
    min_heap = []
    count = 0
    for i in range(N):
        heapq.heappush(min_heap, nums[i])
        count += 1
        if count > k:
            heapq.heappop(min_heap)
   
    return heapq.heappop(min_heap)




nums = [3,2,1,5,6,4]
k = 2
result = findKthLargest(nums, k)
print("result: " + str(result))
#Output: 5

nums = [3,2,1,5,6,4]
result = findKthLargest_using_min_heap(nums, k)
print("result-minheap: " + str(result))



nums = [3,2,3,1,2,4,5,5,6]
k = 4
#Output: 4
result = findKthLargest(nums, k)
print("result: " + str(result))

nums = [3,2,3,1,2,4,5,5,6]
result = findKthLargest_using_min_heap(nums, k)
print("result-minheap: " + str(result))
