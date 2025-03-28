'''
https://leetcode.com/problems/subsets/description/

recursive backtracking

Choice:  either choose a number or not, go to higher index to avoid repetition
                    e.g [1,2,3]  once you are dealt with 1, for 2, consider only 3  in the recursion tree

exit criteia:
    when index = N-1

Parameters: index
'''

def subsets(input):
    result = []
    n = len(input)
    def backtracking(i, sol):
        if i == n:
            result.append(sol[:])
            return
        backtracking(i + 1, sol)

        sol.append(input[i])
        backtracking(i+1, sol)
        sol.pop()

    backtracking(0, [])

    return result


input = [1,2,3]
result = subsets(input)
print("result:" + str(result))

input = [0]
result = subsets(input)
print("result:" + str(result))