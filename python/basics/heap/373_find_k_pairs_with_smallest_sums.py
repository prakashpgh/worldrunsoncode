'''
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

sorted array..
use of heap

take from the arrays... and put it on the heap
visited..
            pop and add to the result...
array => (sum, i+1,j) & (sum,i,j+1) to heap =>  

'''
import heapq

def k_smallest_pairs(nums1: list[int], nums2: list[int], k:int ) -> list[list[int]]:
    if len(nums1) == 0 or len(nums2) == 0 or k == 0:
        return []
    #first element is smallest, put it in the min heap
    min_heap = [(nums1[0] + nums2[0], 0, 0)]
    visited = set((0,0))
    result = []
    while min_heap and k :
        sum, i, j = heapq.heappop(min_heap)
        result.append((nums1[i], nums2[j]))
        k -= 1

        if i+1 < len(nums1) and (i+1,j) not in visited:
            heapq.heappush(min_heap, (nums1[i+1] + nums2[j], i+1, j))
            visited.add((i+1, j))
        if j+1 < len(nums2) and (i,j+1) not in visited:
            heapq.heappush(min_heap, (nums1[i] + nums2[j+1], i, j+1))
            visited.add((i, j+1))
    return result







nums1 = [1,7,11]
nums2 = [2,4,6]
k = 3
#Output: [[1,2],[1,4],[1,6]]
result = k_smallest_pairs(nums1, nums2, k)
print("result: " + str(result))

nums1 = [1,1,2]
nums2 = [1,2,3]
k = 2
#Output: [[1,1],[1,1]]
result = k_smallest_pairs(nums1, nums2, k)
print("result: " + str(result))
