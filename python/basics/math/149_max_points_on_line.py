'''
https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150

find slope of each line with other line,
keep a hashmap
    use atan2 for slope
        use the hashmap inside the first for loop... to avoid duplicates

'''
import sys
import math
import collections

def max_points_on_line(points: list[list[int]]):
    
    n = len(points)
    max_points = 0
    if n == 1:
        return 1
    result = 2

    for i in range(len(points)):
        slopes_map = {}     #mistake this should be inside.... else you would be double counting
        for j in range(len(points)):
            if i != j:
                slope = math.atan2(points[i][1]-points[j][1], points[i][0]-points[j][0])
                if slope in slopes_map:
                    slopes_map[slope] += 1
                else:
                    slopes_map[slope] = 1 
        result = max(result, max(slopes_map.values()) + 1)        
    return result


def maxPoints(points: list[list[int]]) -> int:
        n = len(points)
        if n == 1:
            return 1
        result = 2
        for i in range(n):
            cnt = collections.defaultdict(int)
            for j in range(n):
                if j != i:
                    cnt[
                        math.atan2(
                            points[j][1] - points[i][1],
                            points[j][0] - points[i][0],
                        )
                    ] += 1
            result = max(result, max(cnt.values()) + 1)
        return result


points = [ [-1, 1], [0, 0],[1, 1],[2, 2],[3, 3],[3, 4]]
result = max_points_on_line(points)
print("result: " + str(result))

result = maxPoints(points)
print("result: " + str(result))


points = [[1,1],[2,2],[3,3]]
#3
result = max_points_on_line(points)
print("result: " + str(result))



points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
#4
result = max_points_on_line(points)
print("result: " + str(result))


