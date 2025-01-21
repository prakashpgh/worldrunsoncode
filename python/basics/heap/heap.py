A = [-4, 3, 1,0,2,5,10,8,12,9]

import heapq

#convert array into heap
heapq.heapify(A)

print(str(A))

#heap push
heapq.heappush(A, 4)

print(str(A))

#heap pop
minm = heapq.heappop(A)

print(str(A))

#heap sort
#O( n logN )
#heapify 
#then keep popping from top
def heapsort(array):
    heapq.heapify(array)
    result = []
    l = len(array)
    for i in range(l):
        min = heapq.heappop(A)
        result.append(min)
    return result

print("heapsort...")
A = [1,3,5,7,9,2,4,6,8,0]
result = heapsort(A)
print(str(result))

#

    

