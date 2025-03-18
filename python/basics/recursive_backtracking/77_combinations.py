'''
https://leetcode.com/problems/combinations/

#basecase: len(sol) = 2
#number can be or be in solution...

parameters: 

'''
def combine( n: int, k: int) -> list[list[int]]:
        results = []
        def backtrack(index, solve):
            if len(solve) == k:
                results.append(solve[:])
                return
            for i in range(index, n+1):
                solve.append(i)
                backtrack(i+1, solve)
                solve.pop()
        backtrack(1, [])
        return results


n = 4
k = 2
result = combine(n, k)
print("result: " + str(result))


n = 1
k = 1
#Output: [[1]]
result = combine(n, k)
print("result: " + str(result))
