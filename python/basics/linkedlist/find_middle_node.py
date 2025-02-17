from linkedlist import ListNode

#O(n)
#space O(n)

def find_middle_node(head:ListNode):
    node = head
    slow = node
    fast = node

    while (fast and fast._next):
        fast=fast._next._next
        slow = slow._next
    return slow


A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)
E = ListNode(5)

A._next = B
B._next = C
C._next = D
D._next = E

A.traverse()
result = find_middle_node(A)
print("result:" + str(result))


F = ListNode(6)
E._next = F
A.traverse()
result = find_middle_node(A)
print("result 2:" + str(result))
