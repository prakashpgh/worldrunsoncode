'''
https://leetcode.com/problems/permutations/

# T O(n!)
# S O(n)
# exit condition: length of the solution
# of all possible, add to the solution which does not exist

parameters: solv

choice:
    iterate all the numbers and append the number that is not already there in the result

end criteria:
    when len of the solv = len of candidates
'''
def permutations(nums:list[int])->list[list[int]]:
    result = []
    solution = []
    n = len(nums)

    def backtrack():
        if len(solution) == n:
            result.append(solution[:])
            return
        for en in nums:
            if en not in solution:
                solution.append(en)
                backtrack()
                solution.pop()

    backtrack()
    return result


input = [1,2,3]
result = permutations(input)
print("result:" + str(result))
