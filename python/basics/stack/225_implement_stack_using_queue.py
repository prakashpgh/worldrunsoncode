'''
https://leetcode.com/problems/implement-stack-using-queues/description/

'''

from collections import deque

class MyStack:

    def __init__(self):
        self.s_q = deque()
        self.q = deque()

    def push(self, x: int) -> None:
        while self.s_q:
            self.q.append(self.s_q.popleft())
        self.s_q.append(x)
        while self.q:
            self.s_q.append(self.q.popleft())

    def pop(self) -> int:
        return self.s_q.popleft()

    def top(self) -> int:
        return self.s_q[0]

    def empty(self) -> bool:
        return (len(self.s_q) == 0)
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()