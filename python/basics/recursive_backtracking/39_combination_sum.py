'''
https://leetcode.com/problems/combination-sum/description/

1) Note we dont need exactly k numbers in the combination
2) same number can be repeated

Parameters: index of candidates, we only want to consider the candidates equal to or after the index
            solv[]
            current_sum
Choice:
    with same index => since the same number can be repeated.    
    to call recursively with same index, updated_sum,
End criteria:
    sum == target
        => success
    sum > target     
'''

def combination_sum(candidates: list[int], target:int) -> list[list[int]]:
    results = []

    def backtrack(remain, combination, start):
        if remain == 0:
            results.append(list(combination))
            return
        elif remain < 0:
            return
        
        for i in range(start, len(candidates)):  #mistake
            combination.append(candidates[i])
            backtrack(remain - candidates[i], combination, i) 
            combination.pop()

    backtrack(target, [], 0)
    return results






candidates = [2,3,6,7]
target = 7
#Output: [[2,2,3],[7]]
results = combination_sum(candidates, target)
print("results: " + str(results))


candidates = [2,3,5]
target = 8
#Output: [[2,2,2,2],[2,3,3],[3,5]]


candidates = [2]
target = 1
#Output: []