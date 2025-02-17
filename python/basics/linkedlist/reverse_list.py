from linkedlist import ListNode

def reverseList(head:ListNode)->ListNode:
    print("reverseList")
    node = head
    prev = None
    while node:
        next = node._next
        node._next = prev
        prev = node
        node = next
    return prev



A = ListNode(1)
B = ListNode(1)
C = ListNode(2)
D = ListNode(3)
E = ListNode(3)
A._next = B
B._next = C
C._next = D
D._next = E


A.traverse()
node = reverseList(A)
if node:
    node.traverse()
    print("A: " + str(node))