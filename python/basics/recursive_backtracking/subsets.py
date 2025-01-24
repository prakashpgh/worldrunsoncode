def subsets(input):
    result = []
    sol = []
    n = len(input)
    def backtracking(i):
        if i == n:
            result.append(sol[:])
            return
        backtracking(i + 1)

        sol.append(input[i])
        backtracking(i+1)
        sol.pop()

    backtracking(0)

    return result


input = [1,2,3]
result = subsets(input)
print("result:" + str(result))

input = [0]
result = subsets(input)
print("result:" + str(result))