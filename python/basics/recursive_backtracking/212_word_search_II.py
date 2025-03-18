'''
https://leetcode.com/problems/word-search-ii/

using trie.

1) create a trie of the words..
2) parameters: r, c, current-trie-node
    Choice: up, right, down, left

    end criteria: if the end has the word..

'''

def word_search_II(board: list[list[str]], words: list[str]) -> list[str]: 
    trie = {}
    rows = len(board)
    cols = len(board[0])
    WOD_KEY="$"
    result = []
    def add_words_to_trie():
        for word in words:
            node = trie
            for c in word:
                if c not in node:
                    node[c] = {}
                node = node[c]
                #node = node.setdefault(c, {})
            node[WOD_KEY] = word
    
    add_words_to_trie()
    #print("trie: " + str(trie))
    
    def is_valid(r,c):
        if r >=0 and r < rows and c >= 0 and c < cols:
            return True
        return False

    def backtrack(r, c, parent):
        letter = board[r][c]
      
        current_node = parent[letter]
        match = current_node.pop(WOD_KEY, False)
        if match:
            result.append(match[:])
        
        board[r][c] = "#"
        offsets = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        for off in offsets:
            row = r + off[0]
            col = c + off[1]
            if not is_valid(row, col):
                continue

            if not board[row][col] in current_node:
                continue
            backtrack( row, col, current_node)
        board[r][c] = letter
        
    #print("board-stat: " + str(board))
    for r in range(rows):
        for c in range(cols):
            #print("board[r][c]: " + str(board[r][c]))
            #print("trie: " + str(trie.keys()))
            
            if board[r][c] in trie:
                backtrack(r, c, trie)
    #print("board-end:  " + str(board))
    return result



board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]
words = ["oath","pea","eat","rain"]
words = ["pea","oath","eat","rain"]
#Output: ["eat","oath"]
result = word_search_II(board, words)
print("result: " + str(result))

exit(0)

board = [["a","b"],["c","d"]]
words = ["abcb"]
#Output: []
result = word_search_II(board, words)
print("result: " + str(result))
