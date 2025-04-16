'''
https://leetcode.com/problems/apple-redistribution-into-boxes/description/

'''

def apple_distribution(apple: list[int], capacity: list[int]):
    capacity.sort(reverse=True)
    remaining = sum(apple)
    count = 0
    for c in capacity:
        remaining -= c
        count += 1
        if remaining <= 0:
            break
    return count






apple = [1,3,2]
capacity = [4,3,1,5,2]
#Output: 2
result = apple_distribution(apple, capacity)
print("capacity: " + str(result) )

apple = [5,5,5]
capacity = [2,4,2,7]
#Output: 4
#Explanation: We will need to use all the boxes.
result = apple_distribution(apple, capacity)
print("capacity: " + str(result) )


