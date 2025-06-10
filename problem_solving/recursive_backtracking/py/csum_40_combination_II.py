'''
https://leetcode.com/problems/combination-sum-ii/description/

each number can be used only once.

choices:
    try for all the numbers in the candidates

'''

def combination_sum_use_only_once(candidates: list[int], target:int) -> list[list[int]]:
    results = []

    def backtrack(combination, total_left, index):
        if total_left  == 0:
            results.append(combination[:])
            return results
        if total_left < 0:
            return
        else:
            for i in range(index, len(candidates)):
                if i > index and candidates[i]==candidates[i-1]:
                    continue        
                if total_left < candidates[i]:
                    continue
                combination.append(candidates[i])
                backtrack(combination, total_left - candidates[i], i+1)      
                combination.pop()

    backtrack([], target, 0)       
    return results




candidates = [10,1,2,7,6,1,5]
candidates.sort()
target = 8
result = combination_sum_use_only_once(candidates, target)
print("result: " + str(result))
#Output: [[1,1,6],[1,2,5],[1,7],[2,6]]

candidates = [1,7]
target = 8
result = combination_sum_use_only_once(candidates, target)
print("result: " + str(result))

candidates = [2,5,2,1,2]
target = 5
#Output: [[1,2,2],[5]]
result = combination_sum_use_only_once(candidates, target)
print("result: " + str(result))
