'''
https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

repetitions allowed here.
recursion:
    choices: include the item or exclude the item
    base case: n=0 or w=0, zero
'''

def knapsack_unbounded(values:list[int], weights:list[int], capacity:int) -> int:
    if len(weights) == 0 or len(values)== 0:
        return 0
    
    def recur(n:int, remaining_capacity:int):
        if n==0:
            return 0
        
        include = 0
        if weights[n-1] <= remaining_capacity:
            include = values[n-1] + recur(n, remaining_capacity-weights[n-1] )
        exclude = recur(n-1, remaining_capacity )

        return max(include, exclude)
    return recur(len(values), capacity)

#todo
def knapsack_unbounded_memo(values:list[int], weights:list[int], capacity:int) -> int:
    return -1


#todo
def knapsack_unbounded_iterative(values:list[int], weights:list[int], capacity:int) -> int:
    return -1




capacity = 100
val = [1, 30]
wt = [1, 50]
#Output: 100 
result = knapsack_unbounded(val, wt, capacity)
print("result: " + str(result))

capacity = 8
val = [10, 40, 50, 70]
wt  = [1, 3, 4, 5]        
#Output : 110
result = knapsack_unbounded(val, wt, capacity)
print("result: " + str(result))
