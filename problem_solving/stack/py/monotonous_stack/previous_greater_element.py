'''
https://www.geeksforgeeks.org/previous-greater-element/
'''

def previous_greater_element_brute_force(nums:list[int]) -> list[int]:
    n = len(nums)
    result = [-1] * n
    for i in range(n-1, 0, -1):
        for j in range(i-1, -1, -1):
            if nums[j] > nums[i]:
                result[i] = nums[j]
                break  #*******dont miss this
    return result



def previous_greater_element_stack(nums:list[int]) -> list[int]:
    n = len(nums)
    result = [-1] * n
    stk = []
    for i in range(n-1,-1,-1):
        while stk and nums[i] > stk[len(stk)-1][0]:
           (num, index) = stk.pop() 
           result[index] = nums[i]
        stk.append((nums[i], i))
    return result




array = [10, 4, 2, 20, 40, 12, 30]
output = previous_greater_element_brute_force(array)
print("output-1: " + str(output))

output = previous_greater_element_stack(array)
print("output-2: " + str(output))

output = [-1, 10, 4, -1, -1, 40, 40]

array = [10, 20, 30, 40]
output = previous_greater_element_brute_force(array)
print("output-1: " + str(output))
output = previous_greater_element_stack(array)
print("output-2: " + str(output))
output = [-1,-1,-1,-1]

array = [40, 30, 20, 10]
output = previous_greater_element_brute_force(array)
print("output-1: " + str(output))
output = previous_greater_element_stack(array)
print("output-2: " + str(output))

output = [-1,40,30,20]


