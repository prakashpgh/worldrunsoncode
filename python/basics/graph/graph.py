from graph_node import Node

n=8
A = [[0,1], [1,2],[0,3],[3,4],[3,6],[3,7],[4,2],[4,5],[5,2]]

print("edges list: " + str(A))

#adjacency matrix
M = []
print("adjacency matrix")
for i in range(n):
    M.append([0] * n)


for a,b in A:
    #print("a={} b={}".format(a,b))
    M[a][b] = 1
print("adjacency matrix ="+ str(M))


#edges list to adjacency list
from collections import defaultdict
print("adjacency list")
D=defaultdict(list)
for a,b in A:
    D[a].append(b)

print("adjacenty list="+ str(D))


#dfs..recursive
recursive_list = []
def dfs_recursive(node):
    #print(node)
    recursive_list.append(str(node)+",")
    for neighbor in D[node]:
        if neighbor not in seen:
            seen.add(neighbor)
            dfs_recursive(neighbor)


source = 0
seen = set()
seen.add(source)
print("Dfs recursive:")
dfs_recursive(source)
print("dfs recursive "+ "".join(recursive_list))



#dfs..iterative
dfs_iterative_list = []
def dfs_iterative(node):
    source = 0
    seen = set()
    seen.add(source)

    stack = []
    stack.append(node)
    while stack:
        node = stack.pop()
        #print(node)
        dfs_iterative_list.append(str(node)+",")
        for neighbor in D[node]:
            if neighbor not in seen:
                seen.add(neighbor)
                stack.append(neighbor)



print("Dfs iterative:")
dfs_iterative(0)
print("".join(dfs_iterative_list))


bfs_list = []
from collections import deque
def bfs(source):
    q = deque()
    q.append(source)
    seen = set()
    seen.add(source)

    while q:
        node = q.popleft()
        #print(node)
        bfs_list.append(str(node)+",")
        for neighbor in D[node]:
            if neighbor not in seen:
                seen.add(neighbor)
                q.append(neighbor)



print("Breadth first search")

bfs(0)
print("bfs:" + "".join(bfs_list))

    

A=Node(1)
B=Node(2)
C=Node(3)
D=Node(4)

A._neighbors.append(B)
A._neighbors.append(D)

B._neighbors.append(A)
B._neighbors.append(C)

C._neighbors.append(B)
C._neighbors.append(D)

D._neighbors.append(A)
D._neighbors.append(C)

A.display()

adjList = [[2,4],[1,3],[2,4],[1,3]]
