from linkedlist import SinglyLL

#O(n)
#space O(n)

def find_middle_node(head:SinglyLL):
    node = head
    slow = node
    fast = node

    while (fast and fast._next):
        fast=fast._next._next
        slow = slow._next
    return slow


A = SinglyLL(1)
B = SinglyLL(2)
C = SinglyLL(3)
D = SinglyLL(4)
E = SinglyLL(5)

A._next = B
B._next = C
C._next = D
D._next = E

A.traverse()
result = find_middle_node(A)
print("result:" + str(result))


F = SinglyLL(6)
E._next = F
A.traverse()
result = find_middle_node(A)
print("result 2:" + str(result))
