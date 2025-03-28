'''
https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150

#meta
'''
from linkedlist import ListNode


def add_two_numbers(l1:ListNode,l2: ListNode):
    carry = 0
    l3 = ListNode(0)
    head = l3
    while l1 or l2 or carry:    
        add = 0
        if l1:
            add += l1.val
            l1 = l1.next
        if l2:
            add += l2.val
            l2 = l2.next
        add += carry
        carry = add // 10  #missed the // double
        val = add % 10
        l3.next = ListNode(val)
        l3 = l3.next
    return head.next


A1 = ListNode(2)
B1 = ListNode(4)
C1 = ListNode(3)
A1.next = B1
B1.next = C1
print("A1: " + A1.traverse())

A2 = ListNode(5)
B2 = ListNode(6)
C2 = ListNode(4)
A2.next = B2
B2.next = C2
print("A2: " + A2.traverse())
#l1 = [2,4,3]
#l2 = [5,6,4]
#Output: [7,0,8]
l3 = add_two_numbers(A1, A2)
print("l3: " + l3.traverse())

#------------------------------

l1 = [0]
l2 = [0]
#Output: [0]
l3 = add_two_numbers(A1, A2)
#print("l3: " + l3.traverse())
A1 = ListNode(0)
print("A1: " + A1.traverse())
A2 = ListNode(0)
l3 = add_two_numbers(A1, A2)
print("l3: " + l3.traverse())

#----------------------------------


#l1 = [9,9,9,9,9,9,9]
#l2 = [9,9,9,9]
#Output: [8,9,9,9,0,0,0,1]
A1 = ListNode(9)
B1 = ListNode(9)
C1 = ListNode(9)
D1 = ListNode(9)
E1 = ListNode(9)
F1 = ListNode(9)
G1 = ListNode(9)

A1.next = B1
B1.next = C1
C1.next = D1
D1.next = E1
E1.next = F1
F1.next = G1

print("A1: " + A1.traverse())

A2 = ListNode(9)
B2 = ListNode(9)
C2 = ListNode(9)
D2 = ListNode(9)
A2.next = B2
B2.next = C2
C2.next = D2
print("A2: " + A2.traverse())
l3 = add_two_numbers(A1, A2)
print("l3: " + l3.traverse())
