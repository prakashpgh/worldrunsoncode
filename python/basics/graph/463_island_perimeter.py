'''
https://leetcode.com/problems/island-perimeter/description/

this is not a graph problem.. its simpler
iterate thru the grid, find the cells with 1, perimeter = 4 - (cells surrounded with 1)
'''



def island_perimeter(grid: list[list[int]]):
    rows = len(grid)
    cols = len(grid[0])

    def is_valid(r, c):
        if r >= 0 and r < rows and c >= 0 and c < cols:
            return True
        return False
    
    perimeter = 0
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 0:
                continue
            else:
                offsets = [(0,-1), (-1, 0), (0, 1), (1,0)]
                for off in offsets:
                    i = r + off[0]
                    j = c + off[1]
                    if not is_valid(i, j):
                        perimeter += 1    
                        continue
                    if grid[i][j] == 0:
                        perimeter += 1    
    return perimeter



grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
#Output: 16
result = island_perimeter(grid)
print("result=" + str(result))

grid = [[1]]
#Output: 4
result = island_perimeter(grid)
print("result=" + str(result))


grid = [[1,0]]
#Output: 4
result = island_perimeter(grid)
print("result=" + str(result))
