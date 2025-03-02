'''
https://leetcode.com/problems/intersection-of-two-linked-lists/

Approach 1:
calculate the lengths, point the LL with longer length to the same point as shorter length.
the idea is the intersection point should be starting from here till end
now forward ptrs of each LL and check if they are same.  Note we are comparing the actual node not the values

Approach 2:
without calculating the lengths, we can traverse both LLs and if we reach the end, we can start from the other LL
this way we can find the intersection point

t: O(M+N)
s: O(1)

'''


from linkedlist import ListNode

def getIntersectionNode( headA: ListNode, headB: ListNode) -> ListNode:
    #get lengths of the 2 linked lists
    tempA = headA
    lenA = 0
    while tempA:
        lenA += 1
        tempA = tempA.next
    
    tempB = headB
    lenB = 0
    while tempB:
        lenB += 1
        tempB = tempB.next

    #advance the longer LL by the difference
    tempA = headA
    tempB = headB
    diff = abs(lenA-lenB)
    if diff:
        i = diff
        temp = headA
        if lenA < lenB:
            temp = headB
        
        while temp and i:
            temp = temp.next
            i -= 1
        if lenA > lenB:
            tempA = temp
        else:
            tempB = temp

    #check if they are the same
    while tempA != tempB:
        if not tempA or not tempB:
            return None

        tempA = tempA.next
        tempB = tempB.next
    return tempA


def getIntersectionNode_without_length( headA: ListNode, headB: ListNode) -> ListNode:
    tempA = headA
    tempB = headB
    while tempA != tempB:
        tempA = tempA.next if tempA else headB
        tempB = tempB.next if tempB else headA
    return tempA


#[2,2,4,5,4]
#[2,2,4,5,4]
A = ListNode(2)
B = ListNode(2)
C = ListNode(4)
D = ListNode(5)
E = ListNode(4)

A.next = B
B.next = C
C.next = D
D.next = E

A1 = ListNode(2)
B1 = ListNode(2)
C1 = C
A1.next = B1
B1.next = C1

node = getIntersectionNode(A, A1)
print("intersection: " + str(node))

node = getIntersectionNode_without_length(A, A1)
print("getIntersectionNode_without_length: " + str(node))


#---

#4
A = ListNode(4)
B = ListNode(1)
C = ListNode(8)
D = ListNode(4)
E = ListNode(5)

A.next = B
B.next = C
C.next = D
D.next = E

A1 = ListNode(5)
B1 = ListNode(6)
C1 = ListNode(1)
D1 = C

A1.next = B1
B1.next = C1
C1.next = D1

print( "traverse: " + A.traverse())
print( "traverse: " + A1.traverse())

node = getIntersectionNode(A, A1)
print("intersection: " + str(node))

node = getIntersectionNode_without_length(A, A1)
print("getIntersectionNode_without_length: " + str(node))


