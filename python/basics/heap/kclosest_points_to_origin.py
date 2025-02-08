'''
https://leetcode.com/problems/k-closest-points-to-origin/description/

'''
import cmath
import heapq

# time: O(n log K)
# space: O(k)
def kclosest_points_to_origin(points: list[list[int]], k: int) -> list[list[int]]:
    closest = []
    for x,y in points:
        dist = (x*x + y*y)  #formula mistake
        if len(closest) < k:
            heapq.heappush(closest, (-dist, x, y))  
        else:
            heapq.heappushpop(closest, (-dist, x, y))
    return [(x,y) for d,x,y in closest]


points=[[-5,4],[-6,-5],[4,6]]
k=2
result = kclosest_points_to_origin(points, k)
print("result: " + str(result))


points = [[1,3],[-2,2]]
k = 1
#Output: [[-2,2]]
result = kclosest_points_to_origin(points, k)
print("result: " + str(result))

points = [[3,3],[5,-1],[-2,4]]
k = 2
#Output: [[3,3],[-2,4]]
result = kclosest_points_to_origin(points, k)
print("result: " + str(result))
