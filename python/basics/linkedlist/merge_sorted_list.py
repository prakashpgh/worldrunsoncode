from linkedlist import SinglyLL

def merge_sorted_list(list1:SinglyLL, list2:SinglyLL)->SinglyLL:
    print("merge_sorted_list")
    node1=list1
    node2=list2
    result = None
    result_node = None
    while node1 and node2:
        val = -1
        if node1._val < node2._val:
            val = node1._val
            node1=node1._next
        else:
            val = node2._val
            node2=node2._next

        if result == None:
            result = SinglyLL(val)
            resultNode = result
        else:
            resultNode._next = SinglyLL(val)
            resultNode = resultNode._next
    node = node1
    if not node:
        node = node2
    while node:
        if resultNode:
            resultNode._next = SinglyLL(node._val)
            resultNode = resultNode._next
        else:
            result = SinglyLL(node._val)
            resultNode = result
        node = node._next

    return result



A = SinglyLL(1)
B = SinglyLL(2)
C = SinglyLL(4)
A._next = B
B._next = C
A.traverse()

A1 = SinglyLL(1)
B1 = SinglyLL(3)
C1 = SinglyLL(4)
A1._next = B1
B1._next = C1
A1.traverse()

node = merge_sorted_list(A, A1)
if node:
    node.traverse()
    print("A: " + str(node))