
def bubble_sort(array):
    l = len(array)
    flag = True
    while flag:
        flag = False
        for i in range(1,l):
            if array[i-1] > array[i]:
                array[i-1], array[i] = array[i], array[i-1]
                flag =True
    

A = [-5,3,2,1,-3,-3,7,2,2]
print("bubble_sort")
bubble_sort(A)
print(str(A))


def insertion_sort(array):
    l = len(array)
    for i in range(1, l):
        for j in range(i, 0,-1):
            if array[j] < array[j-1]:
                array[j],array[j-1] = array[j-1], array[j]
            else:
                break

print("insertion_sort")
A = [-5,3,2,1,-3,-3,7,2,2]
insertion_sort(A)
print(str(A))

print("selection_sort")
def selection_sort(array):
    n = len(array)
    for i in range(n):
        min_index = i
        for j in range(i+1, n, 1):
            if array[min_index] > array[j]:
                min_index = j
        array[i], array[min_index] = array[min_index], array[i]


selection_sort(A)
print(str(A))


#divide and conquer
print("merge_sort")

#
def merge_sort(array):
    n = len(array)
    if n == 1:
        return array
    m = n // 2
    L = array[:m]
    T = array[m:]

    print("left: " + str(L))
    print("right:" + str(T))
    L = merge_sort(L)
    T = merge_sort(T)


    print("after left: " + str(L))
    print("after right:" + str(T))

    l = len(L)
    t = len(T)

    i = 0
    j = 0
    r = 0
    result = [0] * n
    while i < l and j < t:
        if L[i] < T[j]:
            result[r] = L[i]
            i = i + 1
        else:
            result[r] = T[j]
            j = j + 1
        r = r + 1
    
    while i < l:
        result[r] = L[i]
        i = i + 1
        r = r + 1

    while j < t:
        result[r] = T[j]
        j = j + 1
        r = r + 1
    return result

A1 = merge_sort(A)
print(str(A1))



def quick_sort(array):
    l = len(array)
    if l <= 1:
        return array
    
    p = array[-1]
    L = [x for x in array[:-1] if x <= p]
    R = [x for x in array[:-1] if x > p]

    L = quick_sort(L)
    R = quick_sort(R)
    return L + [p] + R

print("quick_sort")
A1 = quick_sort(A)
print(str(A1))


A1 = sorted(A)
print(str(A1))


#in place
#A.sort()
#print(str(A))

#counter sort
def counting_sort(array):
    maxx = max(array)
    counts = [0] * (maxx + 1)

    for x in array:
        counts[x] = counts[x] + 1

    print("counts: " + str(counts))
    i = 0
    for c in range(maxx + 1):
        while counts[c] > 0:
            array[i] = c
            i += 1
            counts[c] -= 1

print("counting_sort")
A = [5,3,2,1,3,3,7,2,2]
print(str(A))
counting_sort(A)
print(str(A))

#tuple sort
I = [(-5,3), (2,1), (-3,-3), (7,2),(2,2)]
I_sorted = sorted(I, key=lambda t : t[0])
print(str(I_sorted))
