'''
https://leetcode.com/problems/word-search/description/

recursive backtracking

exit criteria: the word_index = N-1 

Choices: 
    try on all its neighbors

Parameters: grid position, word_index
'''

def word_search(grid:list[list[str]], word)->bool:
    exists = False
    rows = len(grid)
    cols = len(grid[0])
    w = len(word)

    def backtrack(grid_position:tuple, word_index):
        row, col = grid_position
        #print("grid_position: {}    {}".format(row, col))
        if grid[row][col] != word[word_index]:
            return False
        if(word_index == len(word)-1):
            return True

        ch = grid[row][col]
        grid[row][col] = '#'
        #find the neighbors and call backtrack
        #left 
        if(col-1 >=0):
            ret = backtrack((row, col-1), word_index+1)
            if ret:
                return True
        #right
        if(col+1 < cols):
            ret = backtrack((row, col+1), word_index+1)
            if ret:
                return True

        #up
        if(row-1 >=0):
            ret = backtrack((row-1, col), word_index+1)
            if ret:
                return True

        #down
        if(row+1 < rows):
            ret = backtrack((row+1, col), word_index+1)
            if ret:
                return True
            
        grid[row][col] = ch
        return False

    for r in range(rows):
        for c in range(cols):
            if(backtrack((r,c), 0)):
                return True

    return exists




board = [["A","B","C","E"], ["S","F","C","S"],["A", "D","E", "E"]]
word = "SF"
exists = word_search(board, word)
print("exists: " + str(exists))



board = [["A","B","C","E"], ["S","F","C","S"],["A", "D","E", "E"]]
word = "ABCCED"
exists = word_search(board, word)
print("exists: " + str(exists))


board = [["A","B","C","E"], ["S","F","C","S"],["A", "D","E", "E"]]
word = "SEE"
exists = word_search(board, word)
print("exists: " + str(exists))

board = [["A","B","C","E"], ["S","F","C","S"],["A", "D","E", "E"]]
word = "ABCB"
exists = word_search(board, word)
print("exists: " + str(exists))

board = [["A","B","C","E"], ["S","F","C","S"],["A", "D","E", "E"]]
word = "ABCESEEDAS"
exists = word_search(board, word)
print("exists: " + str(exists))
