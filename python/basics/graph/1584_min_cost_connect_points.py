import heapq
#prim algo for MST
#https://leetcode.com/problems/min-cost-to-connect-all-points/description/
#connect everything 
#O( E * log E )
'''
use of minheap
    heap has entry => (distance, index)

intialize heap with the first random one.
while seen nodes < N
    pop from the heap
        add to seen
        add to the cost
    push to the heap distance from this node.

    basically, using the heap, we are getting the next edge which has min. distance from the nodes visited till now.
'''

def min_cost_connect_points(points):
    n = len(points)
    seen = set()
    total_cost = 0
    min_heap = [(0, 0)] #tuple of distace and node index
    #condition for exit - we have seen all the nodes
    while (len(seen) < n):
        dist, i = heapq.heappop(min_heap)
        if i in seen:
            continue
        seen.add(i)
        total_cost += dist
        xi, yi = points[i]
        #get all the unseen points and add it to the heap
        for j in range(n):
            if j not in seen:
                xj, yj = points[j]
                nei_dist = abs(xi-xj) + abs(yi-yj)
                heapq.heappush(min_heap, (nei_dist, j))
    return total_cost



points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
cost = min_cost_connect_points(points)
print("cost:" + str(cost))
#output=20



points = [[3,12],[-2,5],[-4,1]]
cost = min_cost_connect_points(points)
print("cost:" + str(cost))

#output=18



