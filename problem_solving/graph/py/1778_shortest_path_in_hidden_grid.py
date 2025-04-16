'''

'''
# """
# This is GridMaster's API interface.
# You should not implement it, or speculate about its implementation
# """
class GridMaster(object):
    def canMove(self, direction: str) -> bool:
        pass

    def move(self, direction: str) -> None:
        pass        

    def isTarget(self) -> bool:
        pass


from collections import deque
height=500
width=500

def findShortestPath( master: 'GridMaster') -> int:
    # Directions: up, right, down, left
    directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
    dir_chars = ['U', 'R', 'D', 'L']
    opposites = [2, 3, 0, 1]  # Indices of opposite directions for backtracking
    
    # Grid: 0 (unexplored), 1 (open), 2 (blocked), 3 (target)
    grid = [[0] * (height+1) for _ in range(width+1)]
    start_x, start_y = 500, 500  # Arbitrary center to avoid negative indices
    target = [-1, -1]  # To store target coordinates
    
    def dfs(x: int, y: int):
        if master.isTarget():
            target[0], target[1] = x, y
            grid[x][y] = 3
        else:
            grid[x][y] = 1  # Mark as open
        
        # Explore all four directions
        for i, (dx, dy) in enumerate(directions):
            new_x, new_y = x + dx, y + dy
            direction = dir_chars[i]
            
            if grid[new_x][new_y] == 0:  # Unexplored
                if master.canMove(direction):
                    master.move(direction)
                    dfs(new_x, new_y)
                    # Backtrack
                    master.move(dir_chars[opposites[i]])
                else:
                    grid[new_x][new_y] = 2  # Blocked
    
    def bfs() -> int:
        if target[0] == -1 and target[1] == -1:  # Target not found
            return -1
        
        queue = deque([(start_x, start_y)])
        visited = [[False] * (height+1) for _ in range(width+1)]
        visited[start_x][start_y] = True
        distance = 0
        
        while queue:
            level_size = len(queue)
            for _ in range(level_size):
                x, y = queue.popleft()
                if x == target[0] and y == target[1]:
                    return distance
                
                for dx, dy in directions:
                    new_x, new_y = x + dx, y + dy
                    if (0 <= new_x <= width and 0 <= new_y <= height and 
                        not visited[new_x][new_y] and grid[new_x][new_y] != 2):
                        queue.append((new_x, new_y))
                        visited[new_x][new_y] = True
            distance += 1
        return -1  # Target unreachable