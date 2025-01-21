

class SinglyLL:
    def __init__(self, val, next=None):
        self._val = val
        self._next = next

    def __str__(self):
        return str(self._val)



head_single = SinglyLL(1)
B = SinglyLL(2)
C = SinglyLL(3)
D = SinglyLL(4)

head_single._next = B
B._next = C
C._next = D

def traverse(node : SinglyLL):
    while(node is not None):
        print(node)
        node = node._next

def search(head_single : SinglyLL, val):
    node = head
    while node is not None:
        if node._val == val:
            return node
        node = node._next
    return None


traverse(head_single)

node = search(head_single, 8)
if(node is not None):
    print("found...")
    print(node._val)
else:
    print("not found")


class DoubleNode:
    def __init__(self, val, prev=None, next=None):
        self._val = val
        self._prev = prev
        self._next = next

    def __str__(self):
        print(str(self._val))


def displayDD(head : DoubleNode):
    node = head
    elements = []
    while node is not None:
        elements.append(node._val)
    
    print("elements: " + str(len(elements)))
    print(" <-> ".join(elements))

print("doubly node")
head = DoubleNode(1)
displayDD(head)


#reverse linked list
def reverse(head : SinglyLL):
    return head


reverse(head_single)

