#https://leetcode.com/problems/unique-paths/

def unique_paths_bottom_up(m, n):
    result =0
    dp = [] 
    for r in range(m):
        dp.append([0]*n)
    print("dp: " + str(dp))
    dp[0][0] = 1  #1st cell, you can enter only in 1 way
    for r in range(m):
        for c in range(n):
            if r == 0 and c == 0:  #exclude the 1st cell
                continue
            #a cell can be entered only from left or top
            from_left = 0
            from_up = 0
            if c > 0:
                from_left = dp[r][c-1]
            if r > 0:
                from_up = dp[r-1][c]
            dp[r][c] = from_left + from_up
    return dp[m-1][n-1]


'''
start with the target..  
    u can go from up or left..
    base case is top-left
    take care of 1st row and 1st column
'''
def unique_paths_top_down_recursion(m, n):
    memo = {}
    memo[(0,0)]=1
    def paths(i, j):
        if (i, j) in memo:
            return memo[(i,j)]
        from_up = 0
        from_left = 0
        if i > 0:
            from_up = paths(i-1, j)
        if j > 0:
            from_left = paths(i, j-1)
        memo[(i,j)] = from_left + from_up
        return memo[(i,j)]
    
    return paths(m-1,n-1)


m=3
n=7
result = unique_paths_bottom_up(m,n)
print("result:" + str(result))

result = unique_paths_top_down_recursion(m,n)
print("result:" + str(result))
#28


m=3
n=2
result = unique_paths_top_down_recursion(m,n)
print("result:" + str(result))
#3
#1. Right -> Down -> Down
#2. Down -> Down -> Right
#3. Down -> Right -> Down

