'''
https://leetcode.com/problems/equal-row-and-column-pairs/

store row,  in a hash table..
then iterate the cols, transform to tuple, and check..
'''

def equal_row_column_pairs(grid: list[list[int]]) -> int:
    rows = len(grid)
    cols = len(grid[0])
    hash = {}
    count = 0
    for r in range(rows):
        if tuple(grid[r]) in hash:
            hash[tuple(grid[r])] += 1
        else:
            hash[tuple(grid[r])] = 1 
    for c in range(cols):
        t = tuple(r[c] for r in grid)
        if t in hash:
            count += hash[t]
    return count

        


grid = [[3,2,1],[1,7,6],[2,7,7]]
#Output: 1
result = equal_row_column_pairs(grid)
print("result="  + str(result))



grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
#Output: 3
result = equal_row_column_pairs(grid)
print("result="  + str(result))


