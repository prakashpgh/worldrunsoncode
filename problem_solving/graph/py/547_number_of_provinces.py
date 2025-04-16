'''
https://leetcode.com/problems/number-of-provinces/description/

this can be solved by bfs, dfs & disjoint sets.
'''

def number_of_provinces_dfs(connections: list[list[int]]) -> int:
    visited = set()
    rows = len(connections)
    cols = len(connections[0])
    
    def dfs(r):
        visited.add(r)
        for c in range(cols):
            if connections[r][c] != 1:
                continue
            if c in visited:
                continue
            dfs(c)   

    provinces = 0
    
    for r in range(len(connections)):
        if r in visited:
            continue
        provinces += 1
        dfs(r)

    return provinces


connections = [[1,1,0],[1,1,0],[0,0,1]]
#Output: 2
provinces = number_of_provinces_bfs(connections)
print("provinces: " + str(provinces))


connections = [[1,0,0],[0,1,0],[0,0,1]]
#Output: 3
provinces = number_of_provinces_bfs(connections)
print("provinces: " + str(provinces))
