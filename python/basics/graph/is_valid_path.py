from collections import defaultdict

seen = set()
def dfs_recur(input, source:int, destination:int):
    if source == destination:
        return True
    for nei in input[source]:
        if nei not in seen:
            seen.add(nei)
            if dfs_recur(input, nei, destination):
                return True
    return False

def dfs_iterative(input, source:int, destination:int):
    if source == destination:
        return True
    stack = []
    stack.append(source)
    seen.add(source)
    while stack:
        item = stack.pop()
        if item == destination:
            return True
        for nei in input[item]:
            if nei not in seen:
                stack.append(nei)
                seen.add(nei)
    return False

from collections import deque

def bfs(input, source:int, destination:int):
    if source == destination:
        return True

    deq = deque()
    deq.append(source)
    seen.add(source)
    while deq:
        item = deq.popleft()
        if item == destination:
            return True
        for nei in input[item]:
            if nei not in seen:
                deq.append(nei)
                seen.add(nei)
    return False



def does_valid_path_exists(input: list[list[int]], source, destination,method):
    result = False
    #adjacency list
    adj_list = defaultdict(list)
    for i,j in input:
        adj_list[i].append(j)
    print("adj_list: " + str(adj_list))
    #dfs
    if method=="dfs_recur":
        return dfs_recur(adj_list, source, destination)

    #dfs iterative
    if method=="dfs_iterative":
        return dfs_iterative(adj_list, source, destination)

    #bfs
    if method=="bfs":
        return bfs(adj_list, source, destination)

    #bfs
    return result





n=3
input = [[0,1], [1,2],[2,0]]
source = 0
destination = 2
result = does_valid_path_exists(input, source, destination, "dfs_recur")
print("result recur: " + str(result))
seen.clear()
result = does_valid_path_exists(input, source, destination, "dfs_recur")
print("result iterative: " + str(result))

seen.clear()
result = does_valid_path_exists(input, source, destination, "bfs")
print("result bfs: " + str(result))

#True

n=6
input = [[0,1], [0,2],[3,5],[5,4],[4,3]]
source = 0
destination = 5
result = does_valid_path_exists(input, source, destination, "dfs_recur")
print("result recur: " + str(result))
seen.clear()

result = does_valid_path_exists(input, source, destination, "dfs_iterative")
print("result iterative: " + str(result))

result = does_valid_path_exists(input, source, destination, "bfs")
print("result bfs: " + str(result))


#False



