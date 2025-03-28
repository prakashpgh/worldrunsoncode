'''
https://leetcode.com/problems/rotate-list/

draw a list..
iterate and find N, point the last to head
then iterate again and find the last one... N-k-1
point it to null
head to the first one
#revisit
'''
from linkedlist import ListNode

def rotate_list(head:ListNode, k:int) -> ListNode:
    if not head:        #missed corner case
        return None
    node = head
    prev = None
    count = 0
    
    while node:
        prev = node
        node = node.next
        count += 1
    k = k % count
    #close the loop
    prev.next = head
    print("prev: " + str(prev))

    node = head
    for i in range(count - k - 1):
        node = node.next
    print("val: " + str(node))
    head = node.next
    node.next = None
    return head


#head = [1,2,3,4,5]
k = 2
#Output: [4,5,1,2,3]
A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)
E = ListNode(5)
A.next = B
B.next = C
C.next = D
D.next = E
print("traverse: " + A.traverse())
A=rotate_list(A, k)
print("traverse-after: " + A.traverse())


#head = [0,1,2]
k = 4
#Output: [2,0,1]
A = ListNode(0)
B = ListNode(1)
C = ListNode(2)
A.next = B
B.next = C

print("traverse: " + A.traverse())
A=rotate_list(A, k)
print("traverse-after: " + A.traverse())
