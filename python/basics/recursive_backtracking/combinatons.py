#basecase: len(sol) = 2
#number can be or be in solution...
def combinations(n: int, k: int)->list[list[int]]:
    result = []
    solution = []

    def backtrack(x):
        if len(solution) == 2:
            result.append(solution[:])
            return
        if x == 0:
            return

        still_need = k - len(solution)
        backtrack(x-1)
        #if x > still_need:
        #    backtrack(x-1)
        
        solution.append(x)
        backtrack(x-1)
        solution.pop()

    backtrack(4)

    return result


n = 4
k = 2
result = combinations(n, k)
print("result: " + str(result))


