'''
https://www.hackerrank.com/challenges/bfsshortreach/problem
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque

EDGE_WEIGHT=6

def bfs_shortest_path(n, m, edges, s):
    g = {}
    for i, j in edges:
        if i in g:
            g[i].append(j)
        else:
            g[i] = [j]
    print(g)
    output = [-1]*(n+1)
    q = deque()
    q.append((s, 0))
    while q:
        node,dist = q.popleft()
        output[node] = dist
        if node not in g:
            continue
        for nei in g[node]:
            q.append((nei, dist+EDGE_WEIGHT))
    print(output)
    result = []
    for i in range(1,n+1):
        if i != s:
            result.append(output[i])
    return result


n=5
m=3
edges = [[1,2],[1,3],[3,4]]
s = 1
result = bfs_shortest_path(n, m, edges, s)
print("bfs_shortest_path=" + str(result))


n=10
m=8
edges = [[1,2],[1,3],[2,4],[3,5],[4,6],[5,7],[6,8],[9,10]]
s = 1
result = bfs_shortest_path(n, m, edges, s)
print("bfs_shortest_path=" + str(result))


n=10
m=9
edges = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7],[7,8],[8,9],[9,10]]
s = 1
result = bfs_shortest_path(n, m, edges, s)
print("bfs_shortest_path=" + str(result))
