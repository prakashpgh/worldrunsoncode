'''
https://leetcode.com/problems/merge-two-sorted-lists/

our typical merge loop..for both valid lists

#meta
'''
from linkedlist import ListNode

def merge_sorted_list(list1:ListNode, list2:ListNode)->ListNode:
    node1=list1
    node2=list2
    result = ListNode(0)
    resultNode = result
    while node1 and node2:
        val = -1
        if node1.val < node2.val:
            val = node1.val
            node1=node1.next
        else:
            val = node2.val
            node2=node2.next

        resultNode.next = ListNode(val)
        resultNode = resultNode.next
    node = node1
    if not node:
        node = node2
    resultNode.next = node
    return result.next



A = ListNode(1)
B = ListNode(2)
C = ListNode(4)
A.next = B
B.next = C
print( "traverse: " + A.traverse())

A1 = ListNode(1)
B1 = ListNode(3)
C1 = ListNode(4)
A1.next = B1
B1.next = C1
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
