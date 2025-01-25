from linkedlist import SinglyLL

def reverseList(head:SinglyLL)->SinglyLL:
    print("reverseList")
    node = head
    prev = None
    while node:
        next = node._next
        node._next = prev
        prev = node
        node = next
    return prev



A = SinglyLL(1)
B = SinglyLL(1)
C = SinglyLL(2)
D = SinglyLL(3)
E = SinglyLL(3)
A._next = B
B._next = C
C._next = D
D._next = E


A.traverse()
node = reverseList(A)
if node:
    node.traverse()
    print("A: " + str(node))