'''
https://leetcode.com/problems/n-queens-ii/

parameters:
    row, cols, diag_pos, diag_neg

choices:
        cols, pos_diag, neg_diag
    go thru all the columns for a given row.
        
exit condition:
    r == N
'''

def n_queens(n:int):

    def backtrack(r, N, cols, pos_diag, neg_diag):
        if r == N:
            return 1
        sol = 0
        for c in range(n):
            row = r
            col = c

            if col in cols or (row-col) in pos_diag or (row+col) in neg_diag:
                continue
            cols.add(col)
            pos_diag.add(r-c)
            neg_diag.add(r+c)
            sol += backtrack(r+1, N, cols, pos_diag, neg_diag)
            cols.remove(col)
            pos_diag.remove(r-c)
            neg_diag.remove(r+c)    
        return sol        
    
    return backtrack(0, n, set(), set(), set())



n = 4
#Output: 2
result = n_queens(n)
print("result: " + str(result))


n = 1
#Output: 1
result = n_queens(n)
print("result: " + str(result))


n = 8
#Output: 92
result = n_queens(n)
print("result: " + str(result))
