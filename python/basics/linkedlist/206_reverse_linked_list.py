'''
https://leetcode.com/problems/reverse-linked-list/
'''

from linkedlist import ListNode

def reverse_list(head: ListNode) -> ListNode:
    node = head
    prev = None
    while node:
        next_node = node.next
        node.next = prev
        prev = node
        node = next_node
    return prev



A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)
E = ListNode(5)

A.next = B
B.next = C
C.next = D
D.next = E
print(A.traverse())
result = reverse_list(A)
print(result.traverse())
