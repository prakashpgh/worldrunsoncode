'''
https://leetcode.com/problems/snakes-and-ladders/

1-n*n squares.
from say cell 1, you can go in range(current + 1, min(current + 6, N**2) + 1) #+1 is for python range to N-1
    so basically you have this graph..  (directed/unweighted graph.), you need the shortest path
    you can apply BFS

    mapping from numbers 1...n**2 => (r,c) since data is in (r,c)
        odd row, the columns get reversed
          row = num // N  when normal matrix form.  converting to board format => N-1-row
          column: when row is odd, columns are reversed.

    dist[-1] * (N**2) => to store the jumps needed to reach here.
        if next board value is -1, then dist[next] = dist[curr] + 1 [needs one more move from the previous one]

    BFS..
        1 to Q
        while Q:
            pop from Q.
            add the neighbors => you can jump to 6 squares from here... 
                for loop for 6 possible jumps...based on actual number
                    number n =>find r,c find board[r][c]
                    if board[r][c] == -1, nei = n, else nei = board[r][c]
                        destination value ... 1,13(ladder),3....
                        if dist[destination] == -1: #unvisited.
                            dist[destination] = dist[curr]+1
            dist[n*n]
'''

#todo

def snakes_n_ladders():
    pass

