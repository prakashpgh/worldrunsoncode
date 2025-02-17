'''
double knapsack
choices:
    1) dont include the item
    2) include in the first knap
    3) include in the second knap
'''

def double_knapsack(values, capacity1, capacity2):
    number_items = len(values)

    def recur(n, remaining_capacity1, remaining_capacity2):
        if n>=number_items:
            return 0
        if remaining_capacity1==0 and remaining_capacity2==0:
            return 0
        #choice 1 - exclude
        value_0 = recur(n+1, remaining_capacity1, remaining_capacity2)
        value_1 = 0
        value_2 = 0
        #put nth element in the first knap
        if remaining_capacity1 >= values[n]:    #mistake did not add the value to it
            value_1 = values[n] + recur(n+1, remaining_capacity1-values[n], remaining_capacity2)
        #put in 2nd knap
        if remaining_capacity2 >= values[n]:
            value_2 = values[n] + recur(n+1, remaining_capacity1, remaining_capacity2-values[n])
        return max(value_0, value_1, value_2)
    
    return recur(0, capacity1, capacity2)

#todo
def double_knapsack_memo(values, capacity1, capacity2):
    return -1


#todo
def double_knapsack_iterative(values, capacity1, capacity2):
    return -1



arr = [8, 3, 2]
capacity1 = 10
capacity2 = 3 
#Output: 13
result = double_knapsack(arr, capacity1, capacity2)
print("result: " + str(result))


arr = [8, 5, 3] 
capacity1 = 10
capacity2 = 3 
#Output: 11 
result = double_knapsack(arr, capacity1, capacity2)
print("result: " + str(result))
