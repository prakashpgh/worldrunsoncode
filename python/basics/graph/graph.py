n=8
A = [[0,1], [1,2],[0,3],[3,4],[3,6],[3,7],[4,2],[4,5],[5,2]]

M = []
for i in range(n):
    M.append([0] * n)

print("M: " + str(M))


for a,b in A:
    print("a={} b={}".format(a,b))
    M[a][b] = 1
print("M="+ str(M))

#edges list to adjacency list
from collections import defaultdict

D=defaultdict(list)
for a,b in A:
    D[a].append(b)

print("D="+ str(D))

#dfs..recursive
def dfs_recursive(node):
    print(node)
    for neighbor in D[node]:
        if neighbor not in seen:
            seen.add(neighbor)
            dfs_recursive(neighbor)


source = 0
seen = set()
seen.add(source)
print("Dfs recursive:")
dfs_recursive(source)




#dfs..iterative
def dfs_iterative(node):
    source = 0
    seen = set()
    seen.add(source)

    stack = []
    stack.append(node)
    while stack:
        node = stack.pop()
        print(node)
        for neighbor in D[node]:
            if neighbor not in seen:
                seen.add(neighbor)
                stack.append(neighbor)



print("Dfs iterative:")
dfs_iterative(0)

from collections import deque
def bfs(source):
    q = deque()
    q.append(source)
    seen = set()
    seen.add(source)

    while q:
        node = q.popleft()
        print(node)
        for neighbor in D[node]:
            if neighbor not in seen:
                seen.add(neighbor)
                q.append(neighbor)



print("Breadth first search")

bfs(0)

#graphs in classes
class Node:
    def __init__(self, val):
        self._value = val
        self._neighbors =[]

    def __str__(self):
        return f"Node()"
    
    def display(self):
        return f"Node({self._value})"
        #connections = [node._value for node in self._neighbors]
        #return f"is connected to {connections}"
    

A=Node("A")
B=Node("B")
C=Node("C")
D=Node("D")

A._neighbors.append("B")
B._neighbors.append("A")

C._neighbors.append("D")
D._neighbors.append("C")

A.display()