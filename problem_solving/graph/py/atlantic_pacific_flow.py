#find the ones touching the atlantic
#put in a Q, and do a bfs
#follow the same for pacific
#find the intersection
from collections import deque
def atlantic_pacific_flow(heights: list[list[int]])->list[int]:
    result = []
    q_pacific = deque()
    s_pacific = set()
    q_atlantic = deque()
    s_atlantic = set()
    seen_atlantic = set()
    seen_pacific = set()

    rows = len(heights)
    cols = len(heights[0])
    for r in range(len(heights)):
        for c in range(len(heights[0])):
            if r == 0 or c == 0:                       
                q_pacific.append((r, c))
                s_pacific.add((r,c))
                seen_pacific.add((r,c))    
            if r == rows-1 or c == cols-1:                       
                q_atlantic.append((r, c))
                s_atlantic.add((r,c))
                seen_atlantic.add((r,c))    

    def bfs(queue, seen, coords):
        while queue:
            (r,c) = queue.popleft()
            if 0 <= c-1 < cols and 0 <= r < rows and (r,c-1) not in seen and heights[r][c-1] >= heights[r][c]:
                queue.append((r, c-1))
                coords.add((r, c-1))
                seen.add((r,c-1))    
            if 0 <= c+1 < cols and 0 <= r < rows and (r,c+1) not in seen and heights[r][c+1] >= heights[r][c]:
                queue.append((r, c+1))
                coords.add((r, c+1))
                seen.add((r,c+1))    
            if 0 <= c < cols and 0 <= r-1 < rows and (r-1,c) not in seen and heights[r-1][c] >= heights[r][c]:
                queue.append((r-1, c))
                coords.add((r-1, c))
                seen.add((r-1,c))    
            if 0 <= c < cols and 0 <= r+1 < rows and (r+1,c) not in seen and heights[r+1][c] >= heights[r][c]:
                queue.append((r+1, c))
                coords.add((r+1, c))
                seen.add((r+1,c))    

    bfs(q_atlantic, seen_atlantic, s_atlantic)    
    bfs(q_pacific, seen_pacific, s_pacific)   
    for item in s_atlantic:
        if item in s_pacific:
            result.append(item)

    return result



heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
output = atlantic_pacific_flow(heights)
print("output:" + str(output))
#output= [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

heights = [[1]]
output = [[0,0]]