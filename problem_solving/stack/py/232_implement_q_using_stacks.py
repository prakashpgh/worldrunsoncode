'''
https://leetcode.com/problems/implement-queue-using-stacks/

pop is O(1)
push: maintain one queue in Q order  q_stack  .. 
    when pushing empty from this stack into othe stack, push the new element into q_stack... fill this from othe stack

'''

class MyQueue:

    def __init__(self):
        self.q_stack = []
        self.stack = []

    def push(self, x: int) -> None:
        while self.q_stack:
            self.stack.append(self.q_stack.pop())
        self.q_stack.append(x)
        while self.stack:
            self.q_stack.append(self.stack.pop())


    def pop(self) -> int:
        return self.q_stack.pop()    

    def peek(self) -> int:
        return self.q_stack[len(self.q_stack)-1]

    def empty(self) -> bool:
        return (len(self.q_stack) == 0)


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()