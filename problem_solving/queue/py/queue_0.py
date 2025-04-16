#enqueue
#dequeue
#use of a doubly linked list

from collections import deque

d = deque()


d.append(1)
d.append(2)
d.append(3)
d.append(4)

print(str(d))

#dequeue
d.popleft()
print(str(d))


