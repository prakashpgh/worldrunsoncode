'''
https://leetcode.com/problems/rotting-oranges/

use bfs
traverse the matrix, 
    find the fresh oranges, 
    q => fill with rotten 
    while q:
        ==> USE BFS FOr LEVEL ONLY SO YOU DONT GET THE ONCE THAT ARE MARKED ROTTEN, SO YOU COUNT THE MINUTES RIGHT
        add newly rotten to q
        reduce fresh count
        update the grid
        check fresh count == 0
    check fresh count
'''

from collections import deque
#O(m*n)
#space O(m*n)
def rotten_oranges(grid:list[int]):
    rows = len(grid)
    cols = len(grid[0])
    fresh = 0
    queue = deque()
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                fresh += 1
            elif grid[r][c] == 2:
                queue.append((r,c))
    minutes = 0
    while queue:
        minutes += 1
        for _ in range(len(queue)): #=> this line is very important... it makes sure that everything that is in the Q is processed
            (i, j) = queue.popleft()
            print("grid-1:" + str(grid))
            for r,c in [(i-1,j), (i+1,j),(i,j-1), (i,j+1)]:
                if r >=0 and r < rows and c >= 0 and c < cols and grid[r][c] == 1:
                    fresh -= 1
                    queue.append((r,c))
                    grid[r][c] = 2
                
        print("grid-2:" + str(grid) + " minutes: " + str(minutes)) 
        if fresh == 0:
            break
    
    if fresh != 0:
        return -1
    return minutes



#rotten_oranges
grid = [[2,1,1],[1,1,0],[0,1,1]]
minutes = rotten_oranges(grid)
print("minutes: " + str(minutes))
#4


grid = [[2,1,1],[0,1,1],[1,0,1]]
#minutes = rotten_oranges(grid)
print("minutes: " + str(minutes))
#-1


grid = [[0,2]]
#minutes = rotten_oranges(grid)
print("minutes: " + str(minutes))

#0
