'''
https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
'''

from linkedlist import ListNode


def delete_middle_node(head: ListNode) -> ListNode:
    if not head or not head.next:
        return None
    node = head
    node_faster = node.next
    prev = None
    while node_faster:
        prev = node
        node = node.next
        if node_faster:
            node_faster = node_faster.next
            if node_faster:
                node_faster = node_faster.next
    print("middle_node: " + str(node.val))
    if prev and node:
        prev.next = node.next
        
    return head

#head = [1,3,4,7,1,2,6]
#Output: [1,3,4,1,2,6]
A = ListNode(1)
B = ListNode(3)
C = ListNode(4)
D = ListNode(7)
E = ListNode(1)
F = ListNode(2)
G = ListNode(6)

A.next = B
B.next = C
C.next = D
D.next = E
E.next = F
F.next = G

print(A.traverse())
result = delete_middle_node(A)
print(result.traverse())



A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)

A.next = B
B.next = C
C.next = D
#head = [1,2,3,4]
#Output: [1,2,4]
print(A.traverse())
result = delete_middle_node(A)
print(result.traverse())



A = ListNode(2)
B = ListNode(1)
A.next = B
#head = [2,1]
#Output: [2]
print(A.traverse())
result = delete_middle_node(A)
print(result.traverse())

