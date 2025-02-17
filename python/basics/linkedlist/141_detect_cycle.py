'''
https://leetcode.com/problems/linked-list-cycle/

use fast and slow pointers, if they meet, then there is a cycle
'''
from linkedlist import ListNode

#O(n)
#space O(n)

def has_cycle_using_hashset(head:ListNode):
    hash = set()
    node = head
    while node:
        if node in hash:
            return True
        hash.add(node)
        node = node._next
    return False

#Time O(n)
#space O(1)
def has_cycle_using_fast_slow(head:ListNode):
    node = head
    fast = node
    slow = node
    while fast and fast._next:
        slow = slow._next
        fast = fast._next._next
        if slow is fast:
            return True

    return False



A = ListNode(3)
B = ListNode(2)
C = ListNode(0)
D = ListNode(-4)

A._next = B
B._next = C
C._next = D
#D._next = B

A.traverse()
result = has_cycle_using_hashset(A)
print("result:" + str(result))

result = has_cycle_using_fast_slow(A)
print("result has_cycle_using_fast_slow:" + str(result))


D._next = B
result = has_cycle_using_hashset(A)
print("result:" + str(result))

result = has_cycle_using_fast_slow(A)
print("result has_cycle_using_fast_slow:" + str(result))
