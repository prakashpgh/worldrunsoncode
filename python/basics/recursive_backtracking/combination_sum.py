#use the indexes..

def combination_sum(input:list[int], target:int):
    result = []
    sol = []
    n = len(input)
    def backtrack(index):
        if sum(sol) == target:
            result.append(sol[:])
            return
        if sum(sol) > target or index == n:
            return
        
        sol.append(input[index])
        backtrack(index)
        sol.pop()

        backtrack(index+1)

    backtrack(0)

    return result




def combination_sum_causes_duplicates(input:list[int], target:int):
    result = []
    sol = []
    def backtrack():
        if sum(sol) == target:
            result.append(sol[:])
            return
        if sum(sol) > target:
            return
        
        for n in input:
            sol.append(n)
            backtrack()
            sol.pop()
    
    backtrack()

    return result


input=[2,3,6,7]
target=7
result=combination_sum(input, target)
print("result: " + str(result))
#[[2,2,3],[7]]

input=[2,3,5]
target=8
result=combination_sum(input, target)
print("result: " + str(result))
#[[2,2,2,2],[5,3],[2,3,3]]

input=[2]
target=1
result=combination_sum(input, target)
print("result: " + str(result))
#[]

