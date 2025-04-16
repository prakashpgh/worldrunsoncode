'''
https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150

we cannot change the matrix positions directly..
we need to change these to an intermediate number.

'''

def game_of_life(board: list[list[int]]):
    rows = len(board)
    cols = len(board[0])

    neighbours = [(1,0), (0, 1), (-1,0), (0, -1), (-1,-1), (-1,1,), (1,1), (1,-1)]
    for r in range(rows):
        for c in range(cols):
            alive_count = 0
            for n in neighbours:
                row = (r + n[0])
                col = (c + n[1])
                #mistake - did not consider abs or -1.
                if row >= 0 and row < rows and col >= 0 and col < cols and abs(board[row][col])==1:
                    alive_count += 1
            if board[r][c] ==1 and (alive_count < 2 or alive_count > 3):
                board[r][c] = -1
            if board[r][c] == 0  and alive_count == 3:
                board[r][c] = 2


    for r in range(rows):
        for c in range(cols):
            if board[r][c] == -1:
                board[r][c] = 0
            elif board[r][c] == 2:
                board[r][c] = 1

    return



board = [[0,0,0],[1,0,1],[0,1,0]]
print("board-before: " + str(board))
game_of_life(board)
print("board-after: " + str(board))



board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
print("board-before: " + str(board))
#Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
game_of_life(board)
print("board-after: " + str(board))


board = [[1,1],[1,0]]
#Output: [[1,1],[1,1]]