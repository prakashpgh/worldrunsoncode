'''
https://leetcode.com/problems/palindrome-linked-list/

find the mid of the LL
reverse the 2nd half...
compare first half and the 2nd half..
'''

from linkedlist import ListNode

def is_linked_list_palindrome(head: ListNode):
    slow = head
    fast_node = slow
    while fast_node:
        slow = slow.next
        fast_node = fast_node.next
        if fast_node:
            fast_node = fast_node.next

    print("hello-2")    
    node = slow
    prev = None
    while node:
        next = node.next
        node.next = prev
        prev = node
        node = next
    
    first = head
    second = prev
    while first and second:
        if first.val != second.val:
            return False
        first = first.next
        second = second.next
    return True


        

#head = [1,2,2,1]
#Output: true
A = ListNode(1)
B = ListNode(2)
C = ListNode(2)
D = ListNode(1)

A.next = B
B.next = C
C.next = D
print(A.traverse())
result = is_linked_list_palindrome(A)
print("result = " + str(result))




#head = [1,2]
A = ListNode(1)
B = ListNode(2)
A.next = B
result = is_linked_list_palindrome(A)
print("result = " + str(result))



head = [1]
A = ListNode(1)
result = is_linked_list_palindrome(A)
print("result = " + str(result))
