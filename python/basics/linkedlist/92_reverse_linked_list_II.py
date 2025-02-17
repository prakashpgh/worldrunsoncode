'''
https://leetcode.com/problems/reverse-linked-list-ii

#mistake- took a long time to get it correct.
'''
from linkedlist import ListNode

def reverse(head:ListNode, right):
    index = 0
    node = head
    prev = None   #mistake this was set to head
    next = None

    while node and index <= right:
        next = node._next
        node._next = prev
        prev = node
        node = next
        
        index += 1
    return (prev, next)
        


def reverse_linked_list_specific_index(head: ListNode, left:int, right:int) ->ListNode:
    node = head
    index = 1
    prev = None #mistake this was set to head
    while node:
        if index == left:
            reverse_end = node
            #reverse the nodes
            (reverse_start, main_next) = reverse(node, right-left)
            if prev:
                prev._next = reverse_start
            else:
                head = reverse_start
            reverse_end._next = main_next
            return head
            
        prev = node    
        node = node._next
        index += 1
    return None


A = ListNode(3)
B = ListNode(5)
l = 1
r = 2
A._next = B

print("tr: " + A.traverse())
result = reverse_linked_list_specific_index(A, l, r)
print("reverse: " + result.traverse())

##################################################

A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)
E = ListNode(5)
l = 2
r = 4
A._next = B
B._next = C
C._next = D
D._next = E

print("tr: " + A.traverse())
result = reverse_linked_list_specific_index(A, l, r)
print("reverse: " + result.traverse())

###########################

A = ListNode(5)
l = 1
r = 1
print("tr: " + A.traverse())
result = reverse_linked_list_specific_index(A, l, r)
print("reverse: " + result.traverse())

