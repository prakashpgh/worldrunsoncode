'''
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

take care of use case when duplicates are at the start

to delete a node, you need the previous..
once you identify a duplicate value,
skip all the nodes in a while loop... point prev to next
'''
from linkedlist import ListNode
def remove_duplicates_from_sorted_list(head:ListNode) -> ListNode:
    node = head
    prev = None
    
    while node and node._next:
        #values match
        if node._val == node._next._val:
            val = node._val
            while node and node._val == val:
                node = node._next
            if not prev:
                head = node
            else:
                prev._next = node
        else:       #mistake else was missing
            prev = node
            node = node._next
    return head



#head = [1,2,3,3,4,4,5]
#Output: [1,2,5]
A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
C2 = ListNode(3)
D = ListNode(4)
E = ListNode(4)
F = ListNode(5)
A._next = B
B._next = C
C._next = C2
C2._next = D
D._next = E
E._next = F
print("traverse: " + A.traverse())
A=remove_duplicates_from_sorted_list(A)
print("traverse-after: " + A.traverse())

#head = [1,1,1,2,3]
#Output: [2,3]
A = ListNode(1)
B = ListNode(1)
C = ListNode(1)
D = ListNode(2)
E = ListNode(3)
A._next = B
B._next = C
C._next = D
D._next = E
print("traverse: " + A.traverse())
A=remove_duplicates_from_sorted_list(A)
print("traverse-after: " + A.traverse())
