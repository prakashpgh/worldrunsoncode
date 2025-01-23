
def validate_9_squares(input, row, col):
    print("validate_9_squares row: {} col: {}".format(row, col))
    hash = set()
    for r in range(row, row+3,1):
        for c in range(col, col+3,1):
            #print(input[r][c], end="    ")
            if input[r][c] in hash:
                return False
            else:
                hash.add(input[r][c])
        #print(end="\n")
    return True

def valid_sudoku(input):
    #validate rows
    for row in input:
        print("row: " + str(row))
        hash = set()
        for c in row:
            if c == ".":
                continue
            elif c in hash:
                print("row returning false")
                return False
            else:
                hash.add(c)
    #validate columns
    cols = len(input[0])
    for col in range(cols):
        hash = set()
        for row in input:
            c = row[col]
            if c == ".":
                continue
            elif c in hash:
                print("column returning false: " + c + " => " + str(hash))
                return False
            else:
                hash.add(c)
    #validate cube..
    print("validate cube...")
    n = len(input)
    divisor = n//3
    row = 0
    col = 0
    for row in range(0,n,3):
        for col in range(0,n,3):
            validate_9_squares(input, row, col)

    return True


input = [
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]
result = valid_sudoku(input)
print("result:" + str(result))


input = [
    ["8","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]
result = valid_sudoku(input)
print("result:" + str(result))
