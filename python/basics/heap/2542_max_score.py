'''
https://leetcode.com/problems/maximum-subsequence-score/

zip n1 and n2
sort by n2... in decreasing..

iterate this..
    heap push 
    if size > k, heap pop, so we have max k elements in the heap.
    get the max...

'''

from collections import heapq

def max_susequence_score(nums1: list[int], nums2: list[int], k:int) -> int:
    pairs = sorted( zip(nums1, nums2), key=lambda x:x[1], reverse=True)

    heap = []
    max_score = 0
    sum_nums1 = 0
    for n1, n2 in pairs:
        heapq.heappush( heap, n1)
        sum_nums1 += n1

        if len(heap) > k:
            sum_nums1 -= heapq.heappop(heap)

        if len(heap) == k:
            max_score = max(max_score, sum_nums1*n2)
    return max_score