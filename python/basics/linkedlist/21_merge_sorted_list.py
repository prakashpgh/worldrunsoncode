'''
https://leetcode.com/problems/merge-two-sorted-lists/

our typical merge loop..for both valid lists

'''
from linkedlist import ListNode

def merge_sorted_list(list1:ListNode, list2:ListNode)->ListNode:
    node1=list1
    node2=list2
    result = ListNode(0)
    resultNode = result
    while node1 and node2:
        val = -1
        if node1._val < node2._val:
            val = node1._val
            node1=node1._next
        else:
            val = node2._val
            node2=node2._next

        resultNode._next = ListNode(val)
        resultNode = resultNode._next
    node = node1
    if not node:
        node = node2
    resultNode._next = node
    return result._next



A = ListNode(1)
B = ListNode(2)
C = ListNode(4)
A._next = B
B._next = C
print( "traverse: " + A.traverse())

A1 = ListNode(1)
B1 = ListNode(3)
C1 = ListNode(4)
A1._next = B1
B1._next = C1
print( "traverse: " + A1.traverse())


node = merge_sorted_list(A, A1)
if node:
    print( "traverse node: " + node.traverse())
#####################
A = None
#print( "traverse: " + A.traverse())

A1 = None
#print( "traverse: " + A1.traverse())


node = merge_sorted_list(A, A1)
if node:
    print( "traverse node: " + node.traverse())

#######################################
A = None
#print( "traverse: " + A.traverse())

A1 = ListNode(0)
print( "merged: " + A1.traverse())

node = merge_sorted_list(A, A1)
if node:
    print( "merged: " + node.traverse())
#########################
