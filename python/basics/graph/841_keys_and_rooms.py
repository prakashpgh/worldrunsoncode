'''
https://leetcode.com/problems/keys-and-rooms/description/?envType=study-plan-v2&envId=leetcode-75
841_keys_and_rooms.py

create the graph from the links
use bfs
check the len of visited = len of input array

'''
from collections import deque

def keys_and_rooms(rooms: list[list[int]]) -> bool:
    graph = {}
    for i in range(len(rooms)):
        graph[i] = rooms[i]
    visited = set()

    q = deque()
    q.append(0)
    visited.add(0)
    while q:
        val = q.popleft()
        if val not in graph:
            continue
        for nei in graph[val]:
            if nei in visited:
                continue
            visited.add(nei)
            q.append(nei)

    if len(visited) == len(rooms):
        return True
    return False




rooms = [[1],[2],[3],[]]
#Output: true
result = keys_and_rooms(rooms)
print("result: " + str(result))

rooms = [[1,3],[3,0,1],[2],[0]]
#Output: false
result = keys_and_rooms(rooms)
print("result: " + str(result))
