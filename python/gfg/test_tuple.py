#tuples are immutable

print(''*50+"tuple"+''*50 )
my_tuple = (2, 4, "Python", 5.0, -3)
ele_1 = my_tuple[-2] 
ele_2 = my_tuple[2] 
print (ele_1, ele_2)


#tuple packaging and unpackaging
print(''*50+"tuple packing"+''*50 )
packed_tuple = 1, 2, 'three'

# Tuple unpacking
a, b, c = packed_tuple
print (f" packed Tuple : {packed_tuple}, unpacked tuple a: {a}, b: {b}, c : {c}")


#nums = [2, 7, 11, 15]
#target = 9
print(''*50+"2-sum"+''*50 )
def two_sum_tuples(nums, target):
    num_traversed = {}
    for i, num``in enumerate(nums):
        complement = target - num``
        if complement in num_traversed:
            return i, complement
        num_traversed