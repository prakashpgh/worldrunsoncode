'''
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

what we need to find out the routes that need flipping when all the nodes want to go to 0.

1) create the graph from connections.  add a flag for true, and false for artifical route
        we add artifiical only when 0 => a exists.  lets say 0,1 exists, we add 0,1 as True, and 1,0 as False
        the purpose is to visit all nodes.  these will not be used when travesing from nodes to 0.

2) start from 0, and do a dfs using visited.  whereeve it travels via original, mark it as flipped
#tricky
'''
from collections import defaultdict

def reorder_routes_all_paths_to_city_zero(connections: list[list[int]]) ->int :
    graph = defaultdict(list)
    for i,j in connections:
        graph[i].append((j, True))
        graph[j].append((i, False))
    
    visited = set()
    print(graph)

    def dfs(source: int):
        flips = 0
        neigbors = graph[source]
        visited.add(source)
        for (i, actual) in neigbors:
            if i in visited:
                continue
            flips += actual 
            flips += dfs(i)
        return flips
    
    return dfs(0)



n = 6
connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
#Output: 3
result = reorder_routes_all_paths_to_city_zero(connections)
print("result=" + str(result))

n = 5
connections = [[1,0],[1,2],[3,2],[3,4]]
#Output: 2
result = reorder_routes_all_paths_to_city_zero(connections)
print("result=" + str(result))


n = 3
connections = [[1,0],[2,0]]
#Output: 0
result = reorder_routes_all_paths_to_city_zero(connections)
print("result=" + str(result))

