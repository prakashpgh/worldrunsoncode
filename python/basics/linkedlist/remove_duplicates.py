from linkedlist import ListNode


#O(n)
#space O(1)
def delete_duplicates(head:ListNode):
    node = head
    prev = None
    while node:
        #print(node)
        if prev and prev._val == node._val:
            prev._next = node._next
        prev=node
        node = node._next
    return head


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

head = A
#traverse(head)
print("delete duplicates")
delete_duplicates(head)
A.traverse()
#traverse(head)


head=A
#traverse(head)

