'''
https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

here the catch is when you change the col+row to zero, then it affects the existing 1s as well.

Option 1) make a read-only copy, and change the input

Option 2) 
        1st row and 1st column are used as flags for the rows and cols zero... 
        flag kept if the 1st column has to be zerod.
        iterate by exclusing the 1st row and 1st column, and update the 1st row and 1st column

        go thru the 1st row and 1st column and update the zeros
        check 0,0,, and update the 1st rows..
        check the 1st column flag and update the 1st column accordingly
'''

def set_zeros(matrix:list[list[int]]):
    
    if len(matrix)==0:
        return
    rows = len(matrix)
    cols = len(matrix[0])
    print("matrix-input: " + str(matrix))
    #check rows.
    is_col_zero = False
    for r in range(rows):
        if matrix[r][0]==0:
            is_col_zero = True
        for c in range(1, cols):
            if matrix[r][c] == 0:
                matrix[r][0] = 0
                matrix[0][c] = 0

    #starting from cols=1 and rows=1
    for r in range(1, rows):
        for c in range(1, cols):
            if matrix[r][0] == 0 or matrix[0][c]==0:
                matrix[r][c]=0
    #1st row
    if matrix[0][0]==0:
        for j in range(cols):
            matrix[0][j] = 0

    #1st column  => #mistake - this should be done at the end
    if is_col_zero:
        for i in range(rows):
            matrix[i][0] = 0
    print("matrix-after setting zeros: " + str(matrix))

    return


matrix = [[1,2,3,4],[5,0,7,8],[0,10,11,12],[13,14,15,0]]
set_zeros(matrix)
exit(0)


matrix = [[1,1,1],
          [1,0,1],
          [1,1,1]]

set_zeros(matrix)
