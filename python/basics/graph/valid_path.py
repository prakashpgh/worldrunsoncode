
from typing import List
from collections import defaultdict
from collections import deque

#dfs into the source and check if destination is present in the dfs
class ValidPath:
    def valid_path_dfs_recursion(self, n: int, edges: List[List[int]], source : int, destination : int):
        if source == destination:
            return True
        
        # get the edges into a map
        graph = defaultdict(list)
        for (u,v) in edges:
            graph[u].append(v)
            graph[v].append(u)

        print(graph)        

        #visited set
        visited = set()
        visited.add(source)

        def dfs(i):
            if i == destination:
                print("return true")
                return True
            for index in graph[i]:
                if index not in visited:
                    visited.add(index)
                    if(dfs(index)):
                        return True
            return False
        
        return dfs(source)
   
    #use stack for dfs
    def valid_path_dfs_iterative(self, n: int, edges: List[List[int]], source : int, destination : int):
        if source == destination:
            return True
        
        # get the edges into a map
        graph = defaultdict(list)
        for (u,v) in edges:
            graph[u].append(v)
            graph[v].append(u)

        print(graph)        

        #visited set
        visited = set()
        visited.add(source)
        stack =[source]

        while stack:
            node = stack.pop()
            if node == destination:
                return True
            
            for child in graph[node]:
                if child not in visited:
                    visited.add(child)
                    stack.append(child)
        return False

    #use bfs with deque
    def valid_path_bfs_iterative(self, n: int, edges: List[List[int]], source : int, destination : int):
        if source == destination:
            return True
        
        # get the edges into a map
        graph = defaultdict(list)
        for (u,v) in edges:
            graph[u].append(v)
            graph[v].append(u)

        print(graph)        

        #visited set
        visited = set()
        visited.add(source)
        q = deque()
        q.append(source)

        while q:
            node = q.popleft()
            if node == destination:
                return True
            for child in graph[node]:
                if child not in visited:
                    visited.add(child)
                    q.append(child)

        return False

v = ValidPath()
n = 3
edges = [[0,1],[1,2],[2,0]]
source = 0
destination = 2
ret = v.valid_path_dfs_recursion(n, edges, source, destination) 
print("Case I ret: " +  str(ret))

ret = v.valid_path_dfs_iterative(n, edges, source, destination) 
print("Case II ret: " +  str(ret))

ret = v.valid_path_bfs_iterative(n, edges, source, destination) 
print("Case III ret: " +  str(ret))


#case II
n = 6
edges = [[0,1],[0,2],[3,5],[5,4],[4,3]]
source = 0
destination = 5
ret = v.valid_path_dfs_recursion(n, edges, source, destination) 
print("Case II ret: " +  str(ret))

ret = v.valid_path_dfs_iterative(n, edges, source, destination) 
print("Case II ret: " +  str(ret))

ret = v.valid_path_bfs_iterative(n, edges, source, destination) 
print("Case III ret: " +  str(ret))
