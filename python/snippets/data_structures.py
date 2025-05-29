#lists
student_info = [21, 'Rose', "CSE", 30, 40, 50]
print(student_info[-1])  #last element

#slicing.
print(student_info[1:3]) #Rose, CSE

#reverse
student_info[::-1]  #reverse
print(student_info, end=",")
print()

print(student_info[::-2], end=",")  #reverse in steps of 2
print()

#concat
Student_info = [21, "Rose", "CSE", 20, 30, 50, 120]
Student2_info = [22, "John", "ME", 40, 40, 50, 130]
print(Student_info + Student2_info)

#repetition
student_info_repeat = student_info * 2

#common methods.
#len

#sort => in-place, returns None.
    #sorted() => returns a copy

#reverse() => similar to sort, its in-place, returns None
    #reversed() => returns an iterator
    #[::-1] => shallow copy
#min
#max

#iterate
for info in student_info:
    print(info, end= ",")
print()

#range
for i in range(len(student_info)):
    print(student_info[i], end=",")
print()

#reverse iterate
for i in range(len(student_info)-1,-1,-1):
    print(student_info[i], end=",")
print()

#########################################
# multi dim lists
###########################################

list1= [ [1, 2, 3, 5], [4, 6, 7, 9], [8, 10, 11, 13] ]

# printing rows
for i in list1:
    print(i)

#print rows and cols
r = len(list1)
c = 0
if r > 0:
    c = len(list1[0])

for i in range(r):
    for j in range(c):
        print(list1[i][j], end=",")
    print()


#########################################
# list comprehensions
#[expression for item in iterable if condition]

#multidim
#start with the outer loop and then the inner loop
#[expression  outer_loop   inner_loop]
###########################################

#squares
squares_even = [x*x for x in range(21) if x%2 == 0]
print(squares_even)

#create multi-dim 
lst = [[j for j in range(1, 4)] for i in range(3)]
print(lst)

#flattening.
multi_dim_list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
flat_list = [multi_dim_list[i][j] for i in range(3) for j in range(3)]
print(flat_list)
flat_list = [item for sublist in multi_dim_list for item in sublist]
print(flat_list)

######################################################
#dictionary
######################################################
print("dictionaries.. ")
dct_1 = {1: 'A', 2: 'B', 3: 'C', 4: 'D', 5: 'E', 6: 'F'}
print(dct_1)

#remove => del, pop
del dct_1[1]
print(dct_1)

dct_1.pop(2)
print(dct_1)

#update with otherdict.
dct_2 = {26: 'Z', 25: 'Y'}
dct_1.update(dct_2)
print(dct_1)


#iterating.. => keys(), values(), items()
for k,v in dct_1.items():
    print(str(k) + " => " + str(v), end=",")
print()

#dictionary comprehensions
d = {i:i**3 for i in range(10)}
print(d)

# Using dictionary comprehension to create a dictionary of squared even numbers
d = {i : i ** 3 for i in range(21) if i % 2 == 0}
print(d)

matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
d = {(i, j) : matrix[i][j] for i in range(len(matrix)) for j in range(len(matrix[0]))}
print(d)

#find the elements common to all lists and their frequency
def find_common_elements(lists):
    common_elements = {element: min(lst.count(element) for lst in lists) for element in set.intersection(*map(set, lists))}
    return common_elements

list1 = [1, 2, 2, 3, 4]
list2 = [2, 3, 4, 4, 5]
list3 = [3, 4, 5, 5, 6]


############################################
set
#############################################
my_set = {1, 2, 3, 4, 5,5}
print(my_set)

my_set.add(6)
my_set.update([5,6,7,8])
print(my_set)

#discard() =>remove w/o exception if element is not present

#pop() => remove an element, if not present, throws

'''
union()

intersection()

difference()

symmetric_difference()
'''

#############################################################
tuple
##############################################################

#############################################################
#deciding on the data structures
#############################################################
'''
access patterns
    insertions
    lookups
    deletions

space complexity

time complexity

ordered v unordered
'''

