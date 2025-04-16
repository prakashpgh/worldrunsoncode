'''
https://leetcode.com/problems/copy-list-with-random-pointer

iterate the original list, and create the clone nodes.... keep the map in the dictionary
    create the next and randodm pointers as required
'''

from linkedlist import ListNode
#https://www.youtube.com/watch?v=DAzEniVtkMQ
def copy_list_withrandom_pointer(head:ListNode)->ListNode:
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
            new_node = ListNode(node.val)
            hash[node] = new_node
            if not head_new:
                head_new = new_node
        
        #random
        if node.random:
            if node.random in hash:
                new_node.random = hash[node.random]    
            else:
                new_node.random = ListNode(node.random.val)
                hash[node.random] = new_node.random
        #next
        if node.next:
            if node.next in hash:
                new_node.next = hash[node.next]    
            else:
                new_node.next = ListNode(node.next.val)
                hash[node.next] = new_node.next
        node = node.next
        new_node = new_node.next
    return head_new


A = ListNode(7)
B = ListNode(13)
C = ListNode(11)
D = ListNode(10)
E = ListNode(1)

A.next = B
A.random=None
B.next = C
B.random=A
C.next = D
C.random=E
D.next = E
D.random=C
E.random=A

tr = A.traverse(True)
print("tr: " + tr)
n=2
result = copy_list_withrandom_pointer(A)
print("after removing " + str(n) )
tr = result.traverse(True)
print("tr: " + tr)
