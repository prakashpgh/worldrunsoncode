

class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return str(self._val)



head_single = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)

head_single._next = B
B._next = C
C._next = D

def traverse(node : ListNode):
    while(node is not None):
        print(node)
        node = node._next

def search(head_single : ListNode, val):
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
def reverse(head : ListNode):
    return head


reverse(head_single)

