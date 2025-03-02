'''
https://leetcode.com/problems/network-delay-time/description/
Djikstra' algorithm
    heap (distance, node)

    initialize heap with source(0, k)  distance_from_source, node_index
    while (heap is empty)
        pop from heap 
        get neighbors...
        push the total distance from source of neigh. to heap
'''
from collections import defaultdict
import heapq
def network_delay_time(times: list[list[int]], n, k) ->int:
    result = -1
    graph = defaultdict(list)
    for u,v,time in times:
        graph[u].append((v,time))

    min_times = {}
    min_heap = [(0,k)]  #(distance from source, nodeIndex)

    while min_heap:
        time_k_to_i, i = heapq.heappop(min_heap)
        if i in min_times:
            continue

        min_times[i] = time_k_to_i

        #neighbours
        for nei, nei_time in graph[i]:
            #not already visited.
            if nei not in min_times:
                heapq.heappush(min_heap, (time_k_to_i + nei_time, nei))    

    #all were visited
    if len(min_times) == n:    
        return max(min_times.values())
    else:
        return -1


times = [[2,1,1],[2,3,1],[3,4,1]]
n = 4
k = 2
result = network_delay_time(times, n, k)
print("result: " + str(result))
#2

times = [[1,2,1]]
n = 2
k = 1
result = network_delay_time(times, n, k)
print("result: " + str(result))
#1

times = [[1,2,1]]
n = 2
k = 2
result = network_delay_time(times, n, k)
print("result: " + str(result))
#-1


times = [[1,2,1],[1,4,4,],[2,5,10],[2,3,1],[5,4,4,],[3,4,1]]
k=1
n=5
result = network_delay_time(times, n, k)
print("result: " + str(result))
#11