#https://leetcode.com/problems/min-stack/
'''
idea is to have another stack... which keeps the minimum..
if the next push is not the min.  push the latest.
pop... pop as normally
'''

'''
#its a modified version of stack copy.
    a tuple or sub-list is used to keep the count
'''
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




class MinStack:
    def __init__(self):
        self.stk = []
        self.min_stk = []

    def push(self, n):
        self.stk.append(n)
        if not self.min_stk or self.min_stk[len(self.min_stk)-1] > n:
            self.min_stk.append(n)
        else:
            self.min_stk.append(self.min_stk[len(self.min_stk)-1])


    def pop(self):
        self.min_stk.pop()
        return self.stk.pop()


    def top(self):
        return self.stk[len(self.stk)-1]

    def get_min(self):
        return self.min_stk[len(self.min_stk)-1]


#["MinStack","push","push","push","getMin","pop","top","getMin"]
#[[],[-2],[0],[-3],[],[],[],[]]
min_stack = MinStack()
min_stack.push(-2)
min_stack.push(0)
min_stack.push(-3)
min = min_stack.get_min()
print("min: " + str(min))

min_stack.pop()
top = min_stack.top()
print("top: " + str(top))

min = min_stack.get_min()
print("min: " + str(min))

#--------------------------------

min_stack = MinStack_with_tuple()
min_stack.push(-2)
min_stack.push(0)
min_stack.push(-3)
min = min_stack.get_min()
print("min: " + str(min))

min_stack.pop()
top = min_stack.top()
print("top: " + str(top))

min = min_stack.get_min()
print("min: " + str(min))


