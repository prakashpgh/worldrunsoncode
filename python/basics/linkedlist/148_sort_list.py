'''
https://leetcode.com/problems/sort-list/description/?envType=study-plan-v2&envId=top-interview-150

merge sort

1) find the midpoint
2) sort the left part
3) sort the right part
4) merge 

'''

from linkedlist import ListNode


def getMidPoint(head: ListNode) -> ListNode:
    node = head
    faster = head
    prev = None
    while faster:
        prev = node
        node = node.next
        faster = faster.next
        if faster:
            faster = faster.next
    mid = node
    prev.next = None
    return mid

def merge(left: ListNode, right: ListNode) -> ListNode:
    result = ListNode(0)
    result_node = result
    while left and right:
        if left.val <= right.val:
            result_node.next = left
            left = left.next
        else:
            result_node.next = right
            right = right.next
        result_node = result_node.next
    if not left:
        result_node.next=right
    if not right:
         result_node.next=left
    return result.next


def sort_list(head:ListNode):
    if not head or not head.next:
        return head
    
    mid = getMidPoint(head)
    #print("mid: " + mid.traverse())
    #print("left: " + head.traverse())

    #sort
    left = sort_list(head)
    right = sort_list(mid)
    #print("left: " + str(type(left)))
    #print("right: " + str(type(right)))

    return merge(left, right)





head = [4,2,1,3]
#Output: [1,2,3,4]
A = ListNode(4)
B = ListNode(2)
C = ListNode(1)
D = ListNode(3)

A.next = B
B.next = C
C.next = D

print("A: " + A.traverse())
result = sort_list(A)
if result:
    print("result: " + result.traverse())





#-------------------------
head = [-1,5,3,4,0]
#Output: [-1,0,3,4,5]

A = ListNode(-1)
B = ListNode(5)
C = ListNode(3)
D = ListNode(4)
E = ListNode(0)

A.next = B
B.next = C
C.next = D
D.next = E

print("A: " + A.traverse())
result = sort_list(A)
if result:
    print("result: " + result.traverse())

