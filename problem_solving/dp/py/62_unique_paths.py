'''
https://leetcode.com/problems/unique-paths/

number of ways to reach r,c = ways(r-1, c) + ways(r, c-1)
'''

def unique_paths(m:int, n:int) -> int:
    
    def is_valid(r,c):
        if r >= 0 and r < m and c >= 0 and c < n:
            return True
        return False

    def paths(row:int, col:int):
        if not is_valid(row, col):
            return 0
        if row == 0 and col == 1:
            return 1
        elif row == 1 and col == 0:
            return 1
        
        return paths(row-1, col) + paths(row, col-1)

    return paths(m-1, n-1)




m = 3
n = 7
#Output: 28
result = unique_paths(m, n)
print("result = " + str(result))
