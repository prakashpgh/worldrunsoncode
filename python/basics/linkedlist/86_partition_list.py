'''
https://leetcode.com/problems/partition-list/

#mistake took time
#mistake misunderstood the problem..
'''
from linkedlist import ListNode

def partition(head:ListNode, x:int) -> ListNode:
    node = head
    prev_left = None
    right_list = ListNode(0)
    right_list_node = right_list
    while node:
        #create the right 
        if node._val >= x:
            right_list_node._next = node
            right_list_node = node
            next = node._next
            right_list_node._next = None   #mistake .. this line was missing
            #delete from current            
            if prev_left:
                prev_left._next = next
                node = next
                continue
            else:
                #if the 1st node is deleted, make head 
                head = next
                prev_left = None
                node = head
                continue

        prev_left = node
        node = node._next

    if prev_left:
        prev_left._next = right_list._next
    else:
        head = right_list._next
    return head


#head = [2,1]
x = 2
#Output: [1,2]
A = ListNode(2)
B = ListNode(1)
A._next = B

print("result: " + A.traverse())
result = partition(A, x)
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
A._next = B
B._next = C
C._next = D
D._next = E
E._next = F

print("result: " + A.traverse())
result = partition(A, x)
print("result-after-partition: " + result.traverse())


