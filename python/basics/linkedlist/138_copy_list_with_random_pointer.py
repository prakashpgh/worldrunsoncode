'''
https://leetcode.com/problems/copy-list-with-random-pointer

iterate the original list, and create the clone nodes.
    maintain the next and randodm pointers
'''

from linkedlist import ListNode
#https://www.youtube.com/watch?v=DAzEniVtkMQ
def copy_list_with_random_pointer(head:ListNode)->ListNode:
    if not head:
        return None
    node = head
    head_new = None
    new_node = None
    hash = {}
    while node:
        if node in hash:
            new_node = hash[node]
        else:    
            new_node = ListNode(node._val)
            hash[node] = new_node
            if not head_new:
                head_new = new_node
        
        #random
        if node._random:
            if node._random in hash:
                new_node._random = hash[node._random]    
            else:
                new_node._random = ListNode(node._random._val)
                hash[node._random] = new_node._random
        #next
        if node._next:
            if node._next in hash:
                new_node._next = hash[node._next]    
            else:
                new_node._next = ListNode(node._next._val)
                hash[node._next] = new_node._next
        node = node._next
        new_node = new_node._next
    return head_new


A = ListNode(7)
B = ListNode(13)
C = ListNode(11)
D = ListNode(10)
E = ListNode(1)

A._next = B
A._random=None
B._next = C
B._random=A
C._next = D
C._random=E
D._next = E
D._random=C
E._random=A

tr = A.traverse(True)
print("tr: " + tr)
n=2
result = copy_list_with_random_pointer(A)
print("after removing " + str(n) )
tr = result.traverse(True)
print("tr: " + tr)
