A = [-3, -1, 0, 1, 4, 7]
search = 4

def n_order(array, search):
    if search in array:
        print ("exists")

    length = len(array)
    for index in range(length):
        if array[index] == search:
            return index
    return -1

index = n_order(A, search)
print("index: " + str(index))

#traditional binary search
#O( log N)
def binary_search(array, search):
    n = len(array)
    l = 0
    r = n-1
    while l <= r:
        m = l + (r-l)//2
        if array[m] == search:
            return m
        elif array[m] > search:
            r = m -1
        elif array[m] < search:
            l = m +1
    return -1


index = n_order(A, search)
print("binary search index: " + str(index))

index = n_order(A, -9)
print("binary search index: " + str(index))

#condition based binary search
A = [False, False,False,False,True,True,True]
#find the first True

def binary_search_condition_based(array):
    n = len(array)
    l = 0
    r = n -1
    while l < r:
        m = l + (r-l)//2
        if array[m] == False:
            l = m + 1  #we need to get the next since m is false
        elif array[m] == True:
            r = m   #we need to keep m since m-1 could be false
        
    if array[l] == False:
        return -1
    return l


index = binary_search_condition_based(A)
print("binary search condition index: " + str(index))

A = [False, False,False,False,False,False,True]
index = binary_search_condition_based(A)
print("binary search condition index: " + str(index))

A = [False, False,False,False,False,False,False]
index = binary_search_condition_based(A)
print("binary search condition index: " + str(index))