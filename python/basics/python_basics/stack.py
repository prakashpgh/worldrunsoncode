#monotonic stack
'''
increasing or decreasing order
to find the next greater or smaller element in an array

for new addition of num to stack,
    check num > current peek,
    if not, keep poping from the stack, till peek < num
    append num

for increasing, its a good idea to start from the end of the array.
    
'''

def monotonic_increasing(nums: list[int]) -> list[int]:
    N=len(nums)
    stack = []
    for n in nums:
        while stack and stack[len(stack)-1] > n:
            stack.pop()
        stack.append(n)
    result = []
    while stack:
        result.insert(0, stack.pop())
    return result

nums = [3, 1, 4, 1, 5, 9, 2, 6]
result = monotonic_increasing(nums)
print("Monotonic increasing stack:", result)





def monotonic_decreasing(nums: list[int]) -> list[int]:
    N=len(nums)
    stack = []
    for n in nums:
        while stack and stack[len(stack)-1] < n:
            stack.pop()

        stack.append(n)
    print("stack: " + str(stack))

    result = []
    while stack:
        result.insert(0, stack.pop())
    return result

nums = [7,5,9,4]
result = monotonic_decreasing(nums)
print("Monotonic decreasing stack:", result)
#[9,4]


nums = [3, 1, 4, 1, 5, 9, 2, 6]
result = monotonic_decreasing(nums)
print("Monotonic decreasing stack:", result)
#[9,6]

nums = [5, 3, 7, 4, 2, 1]
result = monotonic_decreasing(nums)
print("Monotonic decreasing stack:", result)
#[7,4,2,1]