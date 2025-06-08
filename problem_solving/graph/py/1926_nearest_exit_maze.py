'''
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
1926_maze_exit.py

classic BFS...
start with the entrance in the q.
level order =>to get the number of steps
    find the neighbours. add valid neighbours to the q
    exit when we find a corner cell
'''
from collections import deque



def nearest_exit( maze: list[list[str]], entrance: list[int]) -> int:
    q = deque()
    q.append([entrance[0], entrance[1]])
    rows = len(maze)
    cols = len(maze[0])
    visited = set()
    visited.add((entrance[0], entrance[1]))
    steps = 0
    valid_cells = False
    while q:
        l = len(q)
        for _ in range(l):
            [i, j] = q.popleft()
            
            offsets = [(0,-1), (-1,0), (0, 1), (1,0)]
            for off in offsets:
                r = i + off[0]
                c = j + off[1]
                if (r,c) in visited:
                    continue
                if r < 0 or r >= rows or c < 0 or c >=cols:
                    continue
                if maze[r][c] != ".":
                    continue
                if r == 0 or r == rows-1 or c == 0 or c == cols -1:
                    steps += 1
                    return steps
                visited.add((r,c))    
                q.append((r,c))
                valid_cells = True
        if valid_cells:
            steps += 1
    return -1


maze = [[".","+"]]
entrance = [0,0]
#Output: -1
result = nearest_exit(maze, entrance)
print("result=" + str(result))


maze = [["+","+","+"],[".",".","."],["+","+","+"]]
entrance = [1,0]
#Output: 2
result = nearest_exit(maze, entrance)
print("result=" + str(result))


maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]
entrance = [1,2]
#Output: 1
result = nearest_exit(maze, entrance)
print("result=" + str(result))



