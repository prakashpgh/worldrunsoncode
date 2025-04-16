
'''
https://leetcode.com/problems/course-schedule/
#DETECTING CYCLES

get in adjacency list format.

#convention here is if for course 0, you need prerequisite 1 & 2
#if 0 has prereq 1 and 2, graph 0->1 0->2

for all nodes, you do a dfs, there should not be any cycles.
3 states - unvisited, visiting, visited.
    if the dfs comes to you when you are visiting, then it means cycle

time: O(c+p)
space:O(c+p)

'''
from collections import defaultdict

def course_schedule(num_courses: int, prerequisites: list[list[int]])->bool:
    #getting in adjacency list form...
    result = False
    g = defaultdict(list)
    for i,j in prerequisites:
        g[i].append(j)
    print("g=" + str(g))

    UNVISITED=0
    VISITING=1
    VISITED=2
    states=[UNVISITED]*num_courses
    #do a dfs... if its already visiting, => cycle and return false
    def dfs(course:int)->bool:
        state = states[course]
        if state == VISITING:
            return False
        elif state == VISITED:
            return True

        states[course]=VISITING
        prereq = g[course]
        for c in g[course]:
            #re = dfs(c)
            #print("re: " + type(re))
            if not dfs(c):
                return False
        states[course] = VISITED
        return True
    
    #if any of the course dfs is false, then you cannot complete that course.
    for i in range(num_courses):
        ret = dfs(i)
        if ret == False:
            return False
    return True


num_courses = 2
pre_req = [[1,0]] #to take 1, you have to take 0
result = course_schedule(num_courses, pre_req)
print("result: "  + str(pre_req) + str(result))
#true

num_courses = 2
pre_req = [[1,0], [0,1]] #to take 1, you have to take 0
result = course_schedule(num_courses, pre_req)
print("result: " + str(pre_req) + str(result))
#false

num_courses = 3
pre_req = [[0, 1], [1, 2], [2, 0]] 
result = course_schedule(num_courses, pre_req)
print("result: " + str(pre_req) + str(result))
#false

num_courses = 5
pre_req = [[0, 1], [2, 1], [2, 3], [3,4]] 
result = course_schedule(num_courses, pre_req)
print("result: " + str(pre_req) + str(result))
#true

num_courses = 5
pre_req = [[0, 1], [2, 1], [2, 3], [3,4],[4,2]] 
result = course_schedule(num_courses, pre_req)
print("result: " + str(pre_req) + str(result))
#false
