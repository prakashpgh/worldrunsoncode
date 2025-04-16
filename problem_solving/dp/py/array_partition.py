'''
https://www.geeksforgeeks.org/partition-problem-dp-18/

Approach I:  recursion
get sum of array.
if sum is odd, then its impossible to divide into equal partitions.
if even, then use recursion
    choices: 
        base cases: 
            sum==0, return true
            if number > sum, return false
            if n==0, return false

        either to include the numbe or not

        
'''

def equal_partition(array):
    s = sum(array)
    if s % 2 != 0:
        return False
    
    def recur(n, array, sum):
        if sum == 0:
            return True
        if n==0:
            return False
        
        if array[n-1] > sum:    #mistake missed this line
            return recur(n-1, array, sum)

        #either to include this number or not
        include = recur(n-1, array, sum-array[n-1])
        exclude = recur(n-1, array, sum)
        return include or exclude

    return recur(len(array), array, s//2)


#todo
def equal_partition_memo(array):
    s = sum(array)
    if s % 2 != 0:
        return False
    memo = {}
    def recur(n, array, sum):
        if sum == 0:
            return True
        if n==0:
            return False
        if (n, sum) in memo:
            return memo[(n,sum)]
        
        if array[n-1] > sum:    #mistake missed this line
            memo[(n, sum)] = recur(n-1, array, sum)
            return memo[(n-1, sum)]

        #either to include this number or not
        include = recur(n-1, array, sum-array[n-1])
        exclude = recur(n-1, array, sum)
        memo[(n, sum)] = include or exclude
        return memo[(n, sum)]

    return recur(len(array), array, s//2)



arr = [1, 5, 11, 5]
#Output: True 
result = equal_partition(arr)
print("result: " + str(result))

result = equal_partition_memo(arr)
print("result-memo: " + str(result))

#------------------------------------------

arr = [1, 5, 3]
#Output: False 
result = equal_partition(arr)
print("result: " + str(result))

result = equal_partition_memo(arr)
print("result-memo: " + str(result))
