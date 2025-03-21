'''
328_odd_even_linked_list.py
get the even nodes.. 

result should have the odd nodes.. then followed by the even nodes
even_head_node

for each node...
    get the even
    get the odd.
    continue
'''

from linkedlist import ListNode

def odd_even_linked_list(head: ListNode) -> ListNode:
    if not head:
        return head
    node = head
    even_head = ListNode(0)
    node_even = even_head
    prev = None
    while node:
        prev = node
        even = node.next
        node_even.next = even
        node_even = even
        odd = None
        if even:
            odd = even.next
            even.next = None
        #odd
        node.next = odd
        node = odd
    prev.next = even_head.next
    return head


#head = [1,2,3,4,5]
#Output: [1,3,5,2,4]
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
result = odd_even_linked_list(A)
print(result.traverse())


#head = [2,1,3,5,6,4,7]
#Output: [2,3,6,7,1,5,4]

A = ListNode(2)
B = ListNode(1)
C = ListNode(3)
D = ListNode(5)
E = ListNode(6)
F = ListNode(4)
G = ListNode(7)

A.next = B
B.next = C
C.next = D
D.next = E
E.next = F
F.next = G

print(A.traverse())
result = odd_even_linked_list(A)
print(result.traverse())
