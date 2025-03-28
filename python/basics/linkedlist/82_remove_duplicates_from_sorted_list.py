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
    
    while node and node.next:
        #values match
        if node.val == node.next.val:
            val = node.val
            while node and node.val == val:
                node = node.next
            if not prev:
                head = node
            else:
                prev.next = node
        else:       #mistake else was missing
            prev = node
            node = node.next
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
A.next = B
B.next = C
C.next = C2
C2.next = D
D.next = E
E.next = F
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
A.next = B
B.next = C
C.next = D
D.next = E
print("traverse: " + A.traverse())
A=remove_duplicates_from_sorted_list(A)
print("traverse-after: " + A.traverse())
