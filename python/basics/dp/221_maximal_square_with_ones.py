'''
https://leetcode.com/problems/maximal-square/

https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

idea:
    

    recursive => from [0][0] to m-1,n-1
        if == 0, return zero
        
        a square is formed when right,diag and the down are 1s
        min(right, diag, down)
-------------------
    iterative => fill from the bottom right
        if cell = 0, the memo is zero.
        else min(right, down, diag)
            keep tab on the max..
'''

def maximal_square_with_ones_recur(matrix: list[list[str]]):
    rows = len(matrix)
    cols = len(matrix[0])
    max_square = [0]

    def dp(r, c):
        if r < 0 or r >= rows or c < 0 or c >= cols:
            return 0
        right = dp(r, c+1)
        down = dp(r+1, c)
        diag = dp(r+1, c+1)

        if matrix[r][c] == "0" or matrix[r][c] == 0:
            return 0
        squares = 1 + min(right, down, diag)
        #print("r: " + str(right) + " d: " + str(down) + " x: " + str(diag) + " squares: " + str(squares))
        max_square[0] = max(max_square[0], squares)
        return squares
    dp(0,0)
    return max_square[0]


def maximal_square_with_ones_iterative(matrix: list[list[str]]):
    rows = len(matrix)
    cols = len(matrix[0])
    max_square = 0
    memo = [[0]*(cols+1) for j in range(rows+1)]
    #print("memo: " + str(memo))

    for r in range(rows-1, -1, -1):
        for c in range(cols-1,-1,-1):
            if matrix[r][c] == 0 or matrix[r][c] == "0":
                memo[r][c] = 0
                continue
            memo[r][c] = 1 + min(memo[r+1][c], memo[r][c+1], memo[r+1][c+1])
            max_square = max(memo[r][c], max_square)
    return max_square


mat = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
result = maximal_square_with_ones_iterative(mat)
print("result-iterative: " + str(result))

result = maximal_square_with_ones_recur(mat)
print("result: " + str(result))
#--

mat = [["0","1"],["1","0"]]
result = maximal_square_with_ones_iterative(mat)
print("result-iterative: " + str(result))


mat = [
   [0, 1, 1, 0, 1],
   [1, 1, 0, 1, 0],
   [0, 1, 1, 1, 0],
   [1, 1, 1, 1, 0],
   [1, 1, 1, 1, 1],
   [0, 0, 0, 0, 0] 
   ]
#3
result = maximal_square_with_ones_recur(mat)
print("result: " + str(result))

result = maximal_square_with_ones_iterative(mat)
print("result-iterative: " + str(result))



mat = [[1, 1],
       [1, 1]]
#2
result = maximal_square_with_ones_recur(mat)
print("result: " + str(result))

result = maximal_square_with_ones_iterative(mat)
print("result-iterative: " + str(result))
