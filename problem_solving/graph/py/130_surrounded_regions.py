'''
https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150

1) first iterate the border cells, do a dfs on these, O=>E
2) iterate all the cells, and change O=>X, E=>O

'''

def surrounded_regions(board: list[list[str]]) -> None:
    rows = len(board)
    cols = len(board[0])

    def is_border(r, c):
        if r == 0 or r == rows - 1 or c == 0 or c == cols - 1:
            return True

    def is_valid(r, c):
        if r >= 0 and r < rows and c >=0 and c < cols:
            return True
        return False

    def dfs(r, c):
        offsets = [(0,-1), (-1,0), (0,1), (1,0)]
        for o in offsets:
            row = r + o[0]
            col = c + o[1]
            if not is_valid(row, col):
                continue
            if board[row][col] == "O":
                board[row][col] = "E"
                dfs(row, col)
    #program
    border_rows = [0, rows-1]
    border_cols = [0, cols-1]
    for i in border_rows:
        for j in range(cols):
            if not is_valid(i, j):
                continue
            if board[i][j] == "O":
                board[i][j] = "E"                    
                dfs(i, j)

    for i in range(rows):
        for j in border_cols:
            if not is_valid(i, j):
                continue
            if board[i][j] == "O":
                board[i][j] = "E"                    
                dfs(i, j)

    #mark O=> X, E =>O
    for r in range(rows):
        for c in range(cols):
            if board[r][c] == "O":
                board[r][c] = "X"
            elif board[r][c] == "E":
                board[r][c] = "O"




board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
#Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
print("input: " + str(board))
result = surrounded_regions(board)
print("result: " + str(board))


board = [["X"]]
#Output: [["X"]]
print("input: " + str(board))
result = surrounded_regions(board)
print("result: " + str(board))
