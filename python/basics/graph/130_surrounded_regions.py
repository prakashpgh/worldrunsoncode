'''
https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150

traverse the grid row by row,
when you encounter a 0, dfs on it, change the 0 to X... if its not an edge element... and has X atleast on one of its sides
'''

def surrounded_regions(board: list[list[str]]) -> None:

