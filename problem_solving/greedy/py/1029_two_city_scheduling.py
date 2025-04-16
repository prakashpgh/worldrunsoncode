'''
https://leetcode.com/problems/two-city-scheduling/
'''

def two_city_scheduling(costs: list[list[int]]) -> int:
    costs.sort(key=lambda x:(x[0]-x[1])) 
    total_cost = 0
    N = len(costs) // 2

    for i in range(N):
        total_cost += costs[i][0]

    for i in range(N, 2*N):
        total_cost += costs[i][1]

    return total_cost





costs = [[10,20],[30,200],[400,50],[30,20]]
#Output: 110
result = two_city_scheduling(costs)
print("results = " + str(result))



costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
#Output: 1859
result = two_city_scheduling(costs)
print("results = " + str(result))



costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
#Output: 3086#
result = two_city_scheduling(costs)
print("results = " + str(result))
