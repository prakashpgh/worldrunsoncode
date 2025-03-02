#string formatting
name = "prakashp"
print(f"my name is {name}")


#--------------------------------------------------
#iterating lists
#range(N) is from 0-N-1
print("range demo")
lst = [0,1,3,4,5,6,7,8,9,10]
N = len(lst)
for i in range(N):
    print("lst: " + str(lst[i]))

print("lst:4 " + str(lst[:4]))
print("lst4: " + str(lst[4:]))

print("lst 4:7 " + str(lst[4:7]))

#:4  => till begin till (4-1)
#4: => from 4 till end 
#-1 is the last element of the list
print("lst-1: " + str(lst[:-2]))


print("direct iter demo")
for n in lst:
    print("lst: " + str(n))

#----------------------------------------------

#custom sort
tuples_list = [(3, 4), (1, 2), (5, 1)]
sorted_list = sorted(tuples_list, key=lambda x: x[0] + x[1])
print(sorted_list)
# Output: [(1, 2), (5, 1), (3, 4)]




# the dictionary to be as heap 
my_dict = {'z': 'zebra', 'b': 'ball', 'w': 'whale', 
           'a': 'apple', 'm': 'monkey', 'c': 'cat'} 
  

# dictionary to tuple 
my_list = [(k, v) for k, v in my_dict.items()] 

print("Before organizing as heap :", my_list) 
import heapq
heapq.heapify(my_list)

my_dict = dict(my_list)

print("Resultant dictionary :", my_dict) 

#----------------------------------------------------

#defaultdict


#zip

#================================
'''
matrix
'''
def transpose(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    for r in range(rows):
        for c in range(r+1, cols):
            tmp = matrix[r][c]
            matrix[r][c] = matrix [c][r]
            matrix[c][r] = tmp
    return 


def reflection_vertical(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    for r in range(rows):
        for c in range(cols//2):
            tmp = matrix[r][c] 
            matrix[r][c] = matrix[r][cols-c-1]
            matrix[r][cols-c-1] = tmp

input = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
print("input:" + str(input) )
transpose(input)
print("transpose: " + str(input))
reflection_vertical(input)
print("after reflection: " + str(input))








