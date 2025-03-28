'''
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Traverse one node to nth...this is the fast pointer
slow pointer is pointing to head

now move both slw an fast till fast pointer reaches the end.
    at this point the slow pointer has reached the nth location
'''
from linkedlist import ListNode

def remove_nth_node(head:ListNode, n:int) -> ListNode:
    node = head
    faster_node = None
    for i in range(n):
        node = node.next
    faster_node = node
    node = head
    prev = None
    while faster_node:
        prev = node
        node = node.next
        faster_node = faster_node.next
    if prev:
        prev.next = node.next
    else:
        head = node.next
    return head



A = ListNode(1)
B = ListNode(2)
A.next = B
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
A.next = B
B.next = C
C.next = D
D.next = E
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





