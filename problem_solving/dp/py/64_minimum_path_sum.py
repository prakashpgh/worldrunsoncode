'''
https://leetcode.com/problems/minimum-path-sum

https://leetcode.com/problems/minimum-path-sum/

Idea:
    choices: move down or left..
        current + min( choices )
    base case: off limits inf.  
                if final cell, get its value
    memo: 2 parameters r & c, 2 dim array

    ~~
    iterative approach => fill the r-1, c-1 and back fill                
'''
import sys
def minimum_path_sum_recur(grid):
    rows = len(grid)
    cols = len(grid[0])
    def dp(r, c):
        if r >= rows or c >= cols:
            return sys.maxsize
        if r == rows-1 and c == cols-1:
            return grid[r][c]
        return grid[r][c] + min(dp(r,c+1), dp(r+1,c))
    return dp(0,0)

def minimum_path_sum_recur_memo(grid):
    rows = len(grid)
    cols = len(grid[0])
    memo = [[0]*cols for r in range(rows)]
    memo[rows-1][cols-1] = grid[rows-1][cols-1]
    def dp(r, c):
        if r >= rows or c >= cols:
            return sys.maxsize
        if memo[r][c] != 0:
            return memo[r][c]
        if r == rows-1 and c == cols-1:
            memo[r][c] = grid[r][c]
        memo[r][c] = grid[r][c] + min(dp(r,c+1), dp(r+1,c))
        return memo[r][c]
    return dp(0,0)


def minimum_path_sum_iterative_memo(grid):
    rows = len(grid)
    cols = len(grid[0])
    memo = [[0]*cols for n in range(rows)]
    #last element
    memo[rows-1][cols-1] = grid[rows-1][cols-1]

    for r in range(rows-1,-1,-1):
        for c in range(cols-1,-1,-1):
            if r == rows-1 and c != cols-1:
                memo[r][c] = grid[r][c] + memo[r][c+1]         
            elif r != rows-1 and c == cols-1:
                memo[r][c] = grid[r][c] + memo[r+1][c]         
            elif r < rows-1 and c < cols-1:
                memo[r][c] = grid[r][c] + min(memo[r+1][c], memo[r][c+1])
    return memo[0][0]

#todo
#does not use the whole array
def minimum_path_sum_iterative_memo_optimized(grid):
    return -1


grid = [[1,3,1],[1,5,1],[4,2,1]]
#Output: 7
#Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
result = minimum_path_sum_recur(grid)
print("result-recur:" + str(result))

result = minimum_path_sum_recur_memo(grid)
print("result-recur-memo:" + str(result))

result = minimum_path_sum_iterative_memo(grid)
print("result-minimum_path_sum_iterative_memo:" + str(result))



grid = [[1,2,3],[4,5,6]]
#Output: 12
result = minimum_path_sum_recur(grid)
print("result-recur:" + str(result))

result = minimum_path_sum_recur_memo(grid)
print("result-memo:" + str(result))
