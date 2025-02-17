'''
https://leetcode.com/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-interview-150

#mistake... spent lot of time
make a separate function that would reverse a null ended list & return new_head,new_end

Iterate
maintain counter.
before calling reverse, we need the prev_group_end, next_group_start, start of reverse
'''
from linkedlist import ListNode

#mistake = head changes in reverse.
def reverse(head: ListNode):
    node = head
    new_end = head
    new_head = None
    prev = None
    while node:
        next = node._next
        node._next = prev
        new_head = node
        prev = node
        node = next
    return new_head, new_end


def reverse_nodes_in_k_group(head: ListNode, k):
    node = head
    prev_node = None
    count = 1
    next_node = None
    start = head
    
    while node:
        next_node = node._next
        if count == k:
            next_group_begin = node._next #save this link
            node._next = None
            new_head, new_end = reverse(start)
            if prev_node == None:
                head = new_head
            else:
                prev_node._next = new_head
            new_end._next = next_group_begin
            prev_node = new_end
            count = 0
            start = next_group_begin
        count += 1
        node = next_node
        
    return head



#head = [1,2,3,4,5]
k = 2
#Output: [2,1,4,3,5]
A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)
E = ListNode(5)
A._next = B
B._next = C
C._next = D
D._next = E

print("tr: " + A.traverse())
#head,end = reverse(A)
#print("tr-reversed: " + head.traverse() + " =>  " + str(end))
head = reverse_nodes_in_k_group(A, k)
print("tr-reversed: " + head.traverse() + "     " + str(next))


#head = [1,2,3,4,5]
k = 3
#Output: [3,2,1,4,5]
A = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)
E = ListNode(5)
A._next = B
B._next = C
C._next = D
D._next = E
print("tr: " + A.traverse())
head = reverse_nodes_in_k_group(A, k)
print("tr-reversed: " + head.traverse())
