/*'''
https://leetcode.com/problems/total-cost-to-hire-k-workers/
2642_total_cost_hire_workers
'''
*/

import heapq

def total_cost_hire_workers(costs: list[int], k:int, candidates: int) -> int:
    min_heap = []
    l = 0
    r = len(costs)-1
    for _ in range(candidates):
        if l <= r:
            heapq.heappush(min_heap, (costs[l], l))
            l += 1

    for _ in range(candidates):
        if l <= r:
            heapq.heappush(min_heap, (costs[r], r))
            r -= 1

    total_cost = 0

    for _ in range(k):
        cost, idx = heapq.heappop(min_heap)
        total_cost += cost

        if l <= r:
            if idx < l:
                heapq.heappush(min_heap, (costs[l], l))
                l += 1
            else:
                heapq.heappush(min_heap, (costs[r], r))
                r -= 1
    return total_cost


