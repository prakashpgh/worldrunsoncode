'''
https://leetcode.com/problems/unique-paths-ii
https://www.geeksforgeeks.org/unique-paths-in-a-grid-with-obstacles/

idea:   
    2 choices - right or down.
    base cases: when reached bottom right, path = 1
        when 1, return zero, 
        when out of bounds return zero

    iterative:
        dp[i][j] => number of unique ways to reach that particular cell
        start from top left to bottom right.

        return dp[rows-1][cols-1]

'''

def unique_paths_recurring(obstacle_grid: list[list[int]]):
    rows = len(obstacle_grid)
    cols = len(obstacle_grid[0])
    def unique_paths(i, j):
        if i < 0 or i >= rows or j < 0 or j >= cols:
            return 0
        if i == rows - 1 and j == cols - 1:
            return 1
        if obstacle_grid[i][j] == 1:
            return 0
        
        #choices
        return unique_paths(i+1, j) + unique_paths(i, j+1)
    
    return unique_paths(0,0)



def unique_paths_recurring_memo(obstacle_grid: list[list[int]]):
    rows = len(obstacle_grid)
    cols = len(obstacle_grid[0])
    memo = {}
    def unique_paths(i, j):
        if i < 0 or i >= rows or j < 0 or j >= cols:
            return 0
        if (i,j) in memo:
            return memo[(i,j)]
        if i == rows - 1 and j == cols - 1:
            return 1
        if obstacle_grid[i][j] == 1:
            return 0
        
        #choices
        memo[(i,j)] = unique_paths(i+1, j) + unique_paths(i, j+1)
        return memo[(i,j)]
    
    return unique_paths(0,0)


def unique_paths_iterative(obstacle_grid: list[list[int]]):
    rows = len(obstacle_grid)
    cols = len(obstacle_grid[0])
    dp = [[0]*cols for i in range(rows)]
    if obstacle_grid[0][0] == 0:
        dp[0][0] = 1
    for r in range(rows):
        for c in range(cols):
            if obstacle_grid[r][c] == 1:
                dp[r][c] = 0
            else:
                if r > 0:
                    dp[r][c] += dp[r-1][c]
                if c > 0:
                    dp[r][c] += dp[r][c-1]
    return dp[rows-1][cols-1]

obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
#Output: 2
result = unique_paths_recurring(obstacleGrid)
print("result:  " + str(result))

result = unique_paths_recurring_memo(obstacleGrid)
print("unique_paths_recurring_memo:  " + str(result))

result = unique_paths_iterative(obstacleGrid)
print("unique_paths_iterative:  " + str(result))



obstacleGrid = [[0,1],[0,0]]
#Output: 1
result = unique_paths_recurring(obstacleGrid)
print("result:  " + str(result))

result = unique_paths_recurring_memo(obstacleGrid)
print("unique_paths_recurring_memo:  " + str(result))

result = unique_paths_iterative(obstacleGrid)
print("unique_paths_iterative:  " + str(result))
