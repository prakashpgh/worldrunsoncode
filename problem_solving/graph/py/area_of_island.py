#area of island
#Time: O(m * n)
#Space: O(m * n)
'''
go thru the grids row by row,
if you find 1, increase the island count, and do a dfs,
change all the connected 1s to 0s
'''
def area_of_island(grid):
    rows = len(grid)
    cols = len(grid[0])
    max_area = 0
    
    def dfs(i, j):
        if(i < 0 or i >=rows or j<0 or j >= cols):
            return 0
        if grid[i][j] != 1:
            return 0
        grid[i][j] = 0
        area = 1
        #neighbors
        area += dfs(i,j-1)
        area += dfs(i,j+1)
        area += dfs(i-1,j)
        area += dfs(i+1,j)
        return area

    
    for i in range(rows):
        for j in range(cols):
            #print("grid:"+str(grid[i][j]))
            if grid[i][j] == 1:
                area = dfs(i, j)
                max_area = max(max_area, area)

    return max_area

#6
grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
area = area_of_island(grid)
print("area: " + str(area))

#0
grid = [[0,0,0,0,0,0,0,0]]
area = area_of_island(grid)
print("area: " + str(area))
