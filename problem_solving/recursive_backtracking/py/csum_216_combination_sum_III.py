'''
https://leetcode.com/problems/combination-sum-iii/description/

requirements: 1) we need k numbers in the combination  2) same number cannot be repeated

choice:
    append to the combination - all the numbers greater than that number

parameters: 
    number, sum_remaining, combination


exit criteria
    combination length == k => success  && remain == 0  => append to the result

    failure
        if n > 9
        if remaining sum < 0 or len(com) == k

'''

def combination_sum_three(k:int, n:int) -> list[list[int]]:
    results = []

    def backtrack(sum_remaining, combination, n):
        if sum_remaining == 0 and len(combination) == k:
            results.append(combination[:])
            return
        elif sum_remaining < 0 or len(combination) == k:
            return
        
        for i in range(n, 9):
            combination.append(i+1)
            backtrack(sum_remaining - (i+1), combination, (i+1))
            combination.pop()

    combination = []    
    backtrack(n, combination, 0)
    return results





k = 3
n = 7
#Output: [[1,2,4]]
result = combination_sum_three(k, n)
print("result:" + str(result))


k = 3
n = 9
#Output: [[1,2,6],[1,3,5],[2,3,4]]
result = combination_sum_three(k, n)
print("result:" + str(result))



k = 4
n = 1
#Output: []
result = combination_sum_three(k, n)
print("result:" + str(result))
