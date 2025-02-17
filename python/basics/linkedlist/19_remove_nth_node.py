'''
'''
from linkedlist import ListNode

def remove_nth_node(head:ListNode, n:int) -> ListNode:
    node = head
    faster_node = None
    for i in range(n):
        node = node._next
    faster_node = node
    node = head
    prev = None
    while faster_node:
        prev = node
        node = node._next
        faster_node = faster_node._next
    if prev:
        prev._next = node._next
    else:
        head = node._next
    return head



A = ListNode(1)
B = ListNode(2)
A._next = B
n = 1
print("traverse: " + A.traverse())
A=remove_nth_node(A, n)
if A:
    print("traverse-after: " + A.traverse())
else:
    print("traverse-after: empty" )


A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)
E = ListNode(5)
A._next = B
B._next = C
C._next = D
D._next = E
n = 2
print("traverse: " + A.traverse())
A=remove_nth_node(A, n)
print("traverse-after: " + A.traverse())



A = ListNode(1)
n = 1
print("traverse: " + A.traverse())
A=remove_nth_node(A, n)
if A:
    print("traverse-after: " + A.traverse())
else:
    print("traverse-after: empty" )





