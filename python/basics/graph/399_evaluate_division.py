'''
https://leetcode.com/problems/evaluate-division/
https://www.geeksforgeeks.org/problems/division-problem4236/1

create the graph in the form of dictionary:
    src : [(dest:value) ]

    do a dfs.. from src to destination..
            visited
            exit condition
            
'''
from collections import defaultdict

def calc_equation(equations: list[list[str]], values: list[float], queries: list[list[str]]) -> list[float]: 
    graph = defaultdict(dict)
    N=len(equations)
    for i in range(N):
        graph[equations[i][0]][equations[i][1]] = values[i]
        graph[equations[i][1]][equations[i][0]] = 1.0/values[i]
    print("graph: " + str(graph))
    
    def dfs(x, y, visited):
        if x not in graph or y not in graph:
            return -1
        if y in graph[x]:
            return graph[x][y]
        for i in graph[x]:
            if i not in visited:
                visited.add(i)
                temp = dfs(i, y, visited)
                if temp == -1:
                    continue
                else:
                    return temp * graph[x][i]
        return -1

    output = []
    for p,q in queries:
        output.append(dfs(p, q, set()))
    return output



equations = [["a","b"],["b","c"]]
values = [2.0,3.0]
queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
#Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
result = calc_equation(equations, values, queries)
print("result: " + str(result))
