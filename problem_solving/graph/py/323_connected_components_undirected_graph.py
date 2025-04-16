'''
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/

1) do a dfs..maintain visited set.
2) check visited set for any unvisited nodes. repeat 1) for these nodes.  
The numbe of times you do the dfs => numbe of connected components

'''

def connected_components_undirected_graph(n: int, edges: list[list[int]]):
    pass





n = 5
edges = [[0,1],[1,2],[3,4]]
#Output: 2



n = 5
edges = [[0,1],[1,2],[2,3],[3,4]]
#Output: 1