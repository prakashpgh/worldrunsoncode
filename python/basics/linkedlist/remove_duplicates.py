from linkedlist import SinglyLL


#O(n)
#space O(1)
def delete_duplicates(head:SinglyLL):
    node = head
    prev = None
    while node:
        #print(node)
        if prev and prev._val == node._val:
            prev._next = node._next
        prev=node
        node = node._next
    return head


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

head = A
#traverse(head)
print("delete duplicates")
delete_duplicates(head)
A.traverse()
#traverse(head)


head=A
#traverse(head)

