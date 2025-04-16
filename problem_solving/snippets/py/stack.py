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



class MinStack_with_tuple:
    def __init__(self):
        self.stk = []
        self.min_stk = []

    def push(self, n):
        self.stk.append(n)
        #new minimum pushed..
        #if min. stack is empty or the new item is less than top of min stack
        if not self.min_stk or self.min_stk[len(self.min_stk)-1][0] > n:
            self.min_stk.append([n,1])
        elif n == self.min_stk[len(self.min_stk)-1][0]:
            #same item
            self.min_stk[len(self.min_stk)-1][1] += 1


    def pop(self):
        #reduce the count
        if self.min_stk[-1][0] == self.stk[-1]:
            self.min_stk[-1][1] -= 1
        if self.min_stk[-1][1] == 0:
            self.min_stk.pop()
        return self.stk.pop()


    def top(self):
        return self.stk[len(self.stk)-1]

    def get_min(self):
        return self.min_stk[len(self.min_stk)-1][0]



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