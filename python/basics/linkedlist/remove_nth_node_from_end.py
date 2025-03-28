from linkedlist import ListNode
#remove_nth_node_from_end.py
#https://www.youtube.com/watch?v=fbi4UdayLSA

def remove_nth_node_from_end(head: ListNode, n):
    node = head
    faster = node
    for i in range(n+1):
        if faster:
            faster = faster.next
    if not faster:
        return None
    while faster:
        node=node.next
        faster = faster.next
    if node.next:
        node.next = node.next.next
        
    return head

A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)
E = ListNode(5)

A.next = B
B.next = C
C.next = D
D.next = E

A.traverse()
n=2
result = remove_nth_node_from_end(A, n)
print("after removing " + str(n) )
result.traverse()

#
P = ListNode(1)
P.traverse()
n=1
result = remove_nth_node_from_end(P, n)
print("after removing " + str(n) )
if result:
    result.traverse()
else:
    print("result is None")

#[]

#
X = ListNode(1)
Y = ListNode(2)
X.next = Y
n=1
X.traverse()
result = remove_nth_node_from_end(X, n)
print("after removing " + str(n) )
if result:
    result.traverse()
else:
    print("result is None")
#[1]