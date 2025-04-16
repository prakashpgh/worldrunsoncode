'''
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
2130_maximum_twin_sum_linked_list.py

Approach I:
iterate the linked list, and store the values in a list.
traverse the list with 2-pointer approach.  find the max. sum pair

t: O(n)
s: O(n)

Approach II:
    find middle using fast and slow pointers
    reverse the second half of the LL
    now traverse the first half and the 2nd half, and find the twin sum.. and max. of twin sum
t: O(n)
s: O(1)

'''
from linkedlist import ListNode

def maximum_twin_sum_linked_list(head: ListNode):
    node = head
    values = []
    while node:
        values.append(node.val)
        node = node.next
    max_twin_sum = float('-inf')
    l = 0
    r = len(values)-1
    while l <= r:
        max_twin_sum = max(max_twin_sum, values[l] + values[r])
        l += 1
        r -= 1
    return max_twin_sum


A = ListNode(5)
B = ListNode(4)
C = ListNode(2)
D = ListNode(1)

A.next = B
B.next = C
C.next = D
#head = [5,4,2,1]
#Output: 6
result = maximum_twin_sum_linked_list(A)
print("result="+str(result))

#-------------------------------

A = ListNode(4)
B = ListNode(2)
C = ListNode(2)
D = ListNode(3)

A.next = B
B.next = C
C.next = D

#head = [4,2,2,3]
#Output: 7
result = maximum_twin_sum_linked_list(A)
print("result="+str(result))

#============================
A = ListNode(1)
B = ListNode(100000)

A.next = B
#head = [1,100000]
#Output: 100001
result = maximum_twin_sum_linked_list(A)
print("result="+str(result))

