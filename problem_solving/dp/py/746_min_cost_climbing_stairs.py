'''
https://leetcode.com/problems/min-cost-climbing-stairs/
t: O(N)
s: O(1)

cost of coming to ith floor = min (cost of coming to i-1 + num[i-1],  cost of coming to ith + num[i])
note that the cost 0th and cost 1st = 0 since you can take 1 or 2 steps
'''

def min_cost_climbing_stairs(nums: list[int]) -> int:
    N=len(nums)
    if N < 2:
        return 0
    if N == 2:
        return min(nums[0], nums[1])
    cost_i_minus_one = 0
    cost_i_minus_two = 0
    for i in range(2, N+1):
        cost_i = min(cost_i_minus_one + nums[i-1], cost_i_minus_two + nums[i-2])
        tmp = cost_i_minus_one
        cost_i_minus_one = cost_i
        cost_i_minus_two = tmp
    return cost_i



cost = [10,15,20]
#Output: 15
result = min_cost_climbing_stairs(cost)
print("result: " + str(result))


cost = [1,100,1,1,1,100,1,1,100,1]
#Output: 6
result = min_cost_climbing_stairs(cost)
print("result: " + str(result))
