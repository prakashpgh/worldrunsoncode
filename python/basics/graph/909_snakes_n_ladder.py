'''
https://leetcode.com/problems/snakes-and-ladders

mapping of the columns...

    https://www.youtube.com/watch?v=A7Vdy9-xTjk

    https://www.youtube.com/watch?v=6lH4nO3JfLk&t=575s

    
    BFS since its minimal path..
        children of node to be queued are outcomes +1 ... + 6

        while processing the nodes
            when it reaches N*N, we have reached the destination
            check the value for snake/ladder, need to get some changes to get the values (board reversed)
'''
from collections import deque



def snakes_ladders(board: list[list[int]]):
    board.reverse()
    N=len(board)
    
    def pos_to_rc(num):
        c = (num - 1 ) % N
        r = (num - 1) // N
        if r % 2:
            c = N-1-c
        #r = N-1-r
        return [r,c]

    #val = pos_to_rc(17)

    q = deque()
    q.append([1,0]) #start here. [square-number, steps]
    visited = set()
    while q:
        square, hops = q.popleft()
        #print("square: " + str(square) + " hops: " + str(hops))
        for i in range(1,N+1):
            next_square = square + i
            #print("square: " + str(square) + " next_square: " + str(next_square))
            r,c = pos_to_rc(next_square) 
            if board[r][c] != -1:
                next_square = board[r][c]
            if next_square == N*N:
                return hops+1

            if next_square not in visited:
                visited.add(next_square)
                q.append([next_square, hops + 1])
    return -1


board = [[-1,-1],[-1,3]]
result = snakes_ladders(board)
print("result: " + str(result))


board = [[-1,-1,-1,-1,-1,-1],
         [-1,-1,-1,-1,-1,-1],
         [-1,-1,-1,-1,-1,-1],
         [-1,35,-1,-1,13,-1],
         [-1,-1,-1,-1,-1,-1],
         [-1,15,-1,-1,-1,-1]]
#Output: 4
result = snakes_ladders(board)
print("result: " + str(result))


