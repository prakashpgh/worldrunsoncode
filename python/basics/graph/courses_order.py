from collections import defaultdict

def courses_order(number_courses, prerequisites:list[list[int]])->list[int]:
    result=[]
    graph = defaultdict(list)
    for i,j in prerequisites:
        graph[i].append(j)
    print("graph: " + str(graph))

    states = [0] * number_courses
    UNVISITED=0
    VISITING=1
    VISITED=2
    print("states:" + str(states))

    def dfs(n):
        if states[n] == VISITED:
            return True
        if states[n] == VISITING:
            return False
        states[n] = VISITING
        for c in graph[n]:
            if not dfs(c):
                return False
        states[n] = VISITED
        order.append(n)
        return True
    
    order = []
    for i in range(number_courses):
        if not dfs(i):
            return False
            
    return order

numCourses = 2
prerequisites = [[1,0]]
order = courses_order(numCourses, prerequisites)
print("order: " + str(order))
#output = [0,1]

states=[]
order =[]
numCourses = 4
prerequisites = [[1,0],[2,0],[3,1],[3,2]]
order = courses_order(numCourses, prerequisites)
print("order: " + str(order))
#output: [0,2,1,3]

numCourses = 1
prerequisites = []
order = courses_order(numCourses, prerequisites)
print("order: " + str(order))
#output: [0]

numCourses = 6
prerequisites = [[2,0],[1,0],[0,3],[3,4],[3,5]]
order = courses_order(numCourses, prerequisites)
print("order: " + str(order))
#output: [4,5,3,0,1,2]


