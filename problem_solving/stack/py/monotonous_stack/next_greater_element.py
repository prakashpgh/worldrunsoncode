'''
https://www.geeksforgeeks.org/next-greater-element/
'''

def next_greatest_element(nums:list[int]) -> list[int]:
    n = len(nums)
    result = [-1] * n
    stk = []
    for i in range(n):
        while stk and nums[i] > stk[len(stk)-1][0]: 
            num, index = stk.pop()
            result[index] = nums[i]
        stk.append((nums[i],i))
    return result



array = [1,3,2,4]
output = next_greatest_element(array)
print("output: " + str(output))
output = [3,4,4,-1]

array = [6, 8, 0, 1, 3]
output = next_greatest_element(array)
print("output: " + str(output))
output = [8, -1, 1, 3, -1]

array = [10, 20, 30, 50]
output = next_greatest_element(array)
print("output: " + str(output))
output = [20, 30, 50, -1]

array = [50, 40, 30, 10]
output = next_greatest_element(array)
print("output: " + str(output))
output = [-1, -1, -1, -1]

