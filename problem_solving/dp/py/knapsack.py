'''
https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

recursion:
    can we pick this item.
    if yes
        choice: - either to include the i-th item or not - get max of the 2 choices
        
    basecase: n=0 and w=0, profit = 0
            if weight of nth is > W, then exclude


'''

def knapsack_problem_recur(n:int, W:int, profit:list[int], weights:list[int]):
    if n==0 or W==0:
        return 0
    if weights[n-1] > W:
        return knapsack_problem_recur(n-1, W, profit, weights)
    else:
        return max(profit[n-1] + knapsack_problem_recur(n-1, W - weights[n-1], profit, weights),
                   knapsack_problem_recur(n-1, W, profit, weights))
    return -1


def knapsack_problem_recur_memo(n_items:int, W_total:int, profit:list[int], weights:list[int]):
    memo = {}
    def recur(n:int, W:int):
        if n==0 or W==0:
            return 0
        if (n,W) in memo:
            return memo[(n,W)]
        if weights[n-1] > W:
            memo[(n,W)]=recur(n-1, W)    #exclude nth item
            return memo[(n,W)]
        else:
            memo[(n,W)]= max(profit[n-1] + recur(n-1, W - weights[n-1]),#include nth item profit and weights
                    recur(n-1, W))
            return memo[(n,W)]
    return recur(n_items, W_total)


def knapsack_problem_iterative(N:int, W:int, profit:list[int], weights:list[int]):
    dp = [[0]*(W+1) for i in range(N+1)]
    for n in range(N+1):
        for w in range(W+1):
            if n==0 or w==0:
                dp[n][w]=0
            elif weight[n-1] <= w:
                #dp[n-1][w] => value without including the nth item
                #profit[n-1] => by including nth item + 
                #dp[n-1][w-weights[n-1]] => profit by having other items.  we reduce the index by the weight so we get what weight is remaining and n-1 items.
                dp[n][w] = max(profit[n-1] + dp[n-1][w-weights[n-1]], dp[n-1][w] )
            else: 
                #exclude nth item
                dp[n][w] = dp[n-1][w] 

    return dp[N][W]



W = 4
profit = [1, 2, 3]
weight = [4, 5, 1]
#Output: 3
result = knapsack_problem_recur(len(profit), W, profit, weight)
print("result: " + str(result))

result = knapsack_problem_recur_memo(len(profit), W, profit, weight)
print("result-memo: " + str(result))

result = knapsack_problem_iterative(len(profit), W, profit, weight)
print("result-iterative: " + str(result))


#-------------
N = 3
W = 3
profit = [1, 2, 3]
weight = [4, 5, 6]
#Output: 0
result = knapsack_problem_recur(len(profit), W, profit, weight)
print("result: " + str(result))

result = knapsack_problem_recur_memo(len(profit), W, profit, weight)
print("result-memo: " + str(result))

result = knapsack_problem_iterative(len(profit), W, profit, weight)
print("result-iterative: " + str(result))



profit = [60, 100, 120]
weight = [10, 20, 30]
W = 50
#Output: 220
result = knapsack_problem_recur(len(profit), W, profit, weight)
print("result: " + str(result))

result = knapsack_problem_recur_memo(len(profit), W, profit, weight)
print("result-memo: " + str(result))

result = knapsack_problem_iterative(len(profit), W, profit, weight)
print("result-iterative: " + str(result))
