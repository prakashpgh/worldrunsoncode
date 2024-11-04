Set = {1,2,3, 4,5,7,8,9}
Set.remove(5)
Set.discard(3)
popped_element = Set.pop()
print(Set,f"Popped element is {popped_element}")

#union
print('' * 50 + "union" + '-' * 50)
set1 = {2, 3, 4, 5, 6}
set2 = {4, 5, 7, 9, 1}
union_set = set1.union(set2)
print(union_set)

#intersection
intersection_set = set1.intersection(set2)
print(intersection_set)

#difference
difference_set = set2-set1
print(difference_set)

#symmetric_difference
symmeteric_diff = set1 ^ set2
print(symmeteric_diff)


numbers=[1,2,3,4,5]
average = sum(numbers)/len(numbers)