grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
rows = len(grid)
cols = len(grid[0])

#making tuple out of columns and rows
for c in range(cols):
        t = tuple(r[c] for r in grid)
        print(t)

#rows in tuple
for r in range(rows):
        t = tuple(grid[r])
        print(t)



'''
matrix
'''
def transpose(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    for r in range(rows):
        for c in range(r+1, cols):
            tmp = matrix[r][c]
            matrix[r][c] = matrix [c][r]
            matrix[c][r] = tmp
    return 


def reflection_vertical(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    for r in range(rows):
        for c in range(cols//2):
            tmp = matrix[r][c] 
            matrix[r][c] = matrix[r][cols-c-1]
            matrix[r][cols-c-1] = tmp

input = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
print("input:" + str(input) )
transpose(input)
print("transpose: " + str(input))
reflection_vertical(input)
print("after reflection: " + str(input))
