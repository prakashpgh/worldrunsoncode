'''
https://leetcode.com/problems/triangle/
https://www.geeksforgeeks.org/minimum-sum-path-triangle/

idea is 
    choices available: i and i+1, take min. of the choices
    recur... with row and col changing
                    
    basecase: row and col reach bounds

    memo: there are 2 paramters row and col, so memo will be 2 dim array
'''

def minimum_sum_path_in_triangle(triangle):
    rows = len(triangle)

    def dp(row, col):
        if row >= rows or col >= len(triangle[row]):
            return 0
        return triangle[row][col] + min(dp(row+1, col), dp(row+1, col+1))

    return dp(0, 0)


def minimum_sum_path_in_triangle_memo(triangle):
    rows = len(triangle)
    memo = [[-1]*rows for i in range(rows)]
    def dp(row, col):
        if row >= rows or col >= len(triangle[row]):
            return 0
        if memo[row][col] != -1:
            return memo[row][col]
        
        memo[row][col] = triangle[row][col] + min(dp(row+1, col), dp(row+1, col+1))
        return memo[row][col]
    return dp(0, 0)



def minimum_sum_path_in_triangle_iterative(triangle):
    rows = len(triangle)
    memo = [[-1]*rows for i in range(rows)]
    #
    for i in range(rows):
        memo[rows-1][i] = triangle[rows-1][i]

    for r in range(rows-2, -1, -1):
        for c in range(len(triangle[r])):
            memo[r][c] = triangle[r][c] + min(memo[r+1][c], memo[r+1][c+1])
    return memo[0][0]



triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
#Output: 11
result = minimum_sum_path_in_triangle(triangle)
print("result: " + str(result))
#Explanation: The triangle looks like:
#   2
#  3 4
# 6 5 7
#4 1 8 3
#The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
result = minimum_sum_path_in_triangle_memo(triangle)
print("result-memo: " + str(result))
result = minimum_sum_path_in_triangle_iterative(triangle)
print("result-iterative: " + str(result))




triangle = [[-10]]
#-10

triangle =  [[2], [3, 7], [8, 5, 6],[6, 1, 9, 3]]
#Output: 11 
#Explanation : The path is 2 → 3 → 5 → 1, which results in a minimum sum of 2 + 3 + 5 + 1 = 11.
result = minimum_sum_path_in_triangle(triangle)
print("result: " + str(result))
result = minimum_sum_path_in_triangle_memo(triangle)
print("result-memo: " + str(result))
result = minimum_sum_path_in_triangle_iterative(triangle)
print("result-iterative: " + str(result))


triangle =  [[3], [6, 9], [8, 7, 1], [9, 6, 8, 2]]
#Output: 15
result = minimum_sum_path_in_triangle(triangle)
print("result: " + str(result))
result = minimum_sum_path_in_triangle_memo(triangle)
print("result-memo: " + str(result))
result = minimum_sum_path_in_triangle_iterative(triangle)
print("result-iterative: " + str(result))


triangle = [
    [2],
    [3, 9],
    [1, 6, 7]
]
#6
result = minimum_sum_path_in_triangle(triangle)
print("result: " + str(result))
result = minimum_sum_path_in_triangle_memo(triangle)
print("result-memo: " + str(result))
