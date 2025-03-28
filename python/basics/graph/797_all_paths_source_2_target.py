'''
https://leetcode.com/problems/all-paths-from-source-to-target/

bfs or dfs

#todo
'''
from collections import deque


def all_paths_source_2_target_bfs(graph: list[list[int]]) -> list[list[int]]:
    result = []
    q = deque()
    q.append((0, [0]))
    while q:
        node, path = q.popleft()
        if node == len(graph)-1:
            result.append(path)
            continue
        for nei in graph[node]:
            q.append((nei, path + [nei]))
    return result





graph = [[1,2],[3],[3],[]]
#Output: [[0,1,3],[0,2,3]]
result = all_paths_source_2_target_bfs(graph)
print("result=" + str(result))

graph = [[4,3,1],[3,2,4],[3],[4],[]]
#Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
result = all_paths_source_2_target_bfs(graph)
print("result=" + str(result))


    