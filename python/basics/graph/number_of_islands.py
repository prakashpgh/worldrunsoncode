'''
go thru the grids row by row,
if you find 1, increase the island count, and do a dfs,
change all the connected 1s to 0s
'''
def number_of_islands(grid):
    rows = len(grid)
    cols = len(grid[0])

    def dfs(i, j):
        if(i < 0 or i >=rows or j<0 or j >= cols):
            return
        if grid[i][j] != "1":
            return
        grid[i][j] = "x"
        #neighbors
        dfs(i,j-1)
        dfs(i,j+1)
        dfs(i-1,j)
        dfs(i+1,j)

    islands = 0
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == "1":
                islands += 1
                dfs(i, j)

    return islands


grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
islands = number_of_islands(grid)
#1
print("islands: " + str(islands))


grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
#3
islands = number_of_islands(grid)
print("islands: " + str(islands))

