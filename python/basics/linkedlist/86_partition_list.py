'''
https://leetcode.com/problems/partition-list/

#mistake took time
#mistake misunderstood the problem..
'''
from linkedlist import ListNode

def partition2(head:ListNode, x:int) -> ListNode:
    left_head = ListNode(0)
    right_head = ListNode(0)
    left_node = left_head
    right_node = right_head
    node = head
    middle_node = None
    while node:
        if node.val == x:
            middle_node = node
        elif node.val < x:
            left_node.next = node
            left_node = node
        else:
            right_node.next = node
            right_node = node
        node = node.next
    right_node.next = None
    left_node.next = middle_node
    middle_node.next = right_head.next
    return left_head.next



#head = [2,1]
x = 2
#Output: [1,2]
A = ListNode(2)
B = ListNode(1)
A.next = B

print("A: " + A.traverse())
result = partition2(A, x)
print("result-after-partition: " + result.traverse())

#head = [1,4,3,2,5,2]
x = 3
#[1,2,2,4,3,5]
A = ListNode(1)
B = ListNode(4)
C = ListNode(3)
D = ListNode(2)
E = ListNode(5)
F = ListNode(2)
A.next = B
B.next = C
C.next = D
D.next = E
E.next = F

print("result: " + A.traverse())
result = partition2(A, x)
print("result-after-partition: " + result.traverse())


