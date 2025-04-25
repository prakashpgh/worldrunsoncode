'''
https://leetcode.com/problems/swap-nodes-in-pairs/

        
'''

from linkedlist import ListNode

def reverse(head: ListNode, k:int):
    node = head
    prev = None
    new_tail = head
    while node and k>0:
        #print("k=" + str(k))
        next = node.next
        node.next = prev
        prev = node
        node = next
        k -= 1
    new_head = prev
    next_head = node
    return (new_head, next_head, new_tail)

def swap_node_in_pairs(head: ListNode, k: int) -> ListNode:
    node = head
    reverse_head = None
    new_tail = None
    prev_head = None
    prev_tail = None
    while node:
        (new_head, next_head, new_tail) = reverse(node, k)
        if prev_tail:
            prev_tail.next = new_head
        prev_tail = new_tail
        if not reverse_head:
            reverse_head = new_head
        node = next_head

    return reverse_head


A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)
E = ListNode(5)
F = ListNode(6)
G = ListNode(7)
A.next = B
B.next = C
C.next = D
D.next = E
E.next = F
F.next = G
print( "traverse: " + A.traverse())
(newHead, nextHead, newTail) = reverse(A, 2)
print(newHead.traverse())
if nextHead:
    print(nextHead.traverse())

####################
A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)
E = ListNode(5)
F = ListNode(6)
G = ListNode(7)
A.next = B
B.next = C
C.next = D
D.next = E
E.next = F
F.next = G


print("swap in pairs")
rev = swap_node_in_pairs(A, 2)
if rev:
    print( "rev: " + rev.traverse())

