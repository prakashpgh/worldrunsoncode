

class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return str(self.val)



head_single = ListNode(1)
B = ListNode(2)
C = ListNode(3)
D = ListNode(4)

head_single.next = B
B.next = C
C.next = D

def traverse(node : ListNode):
    while(node is not None):
        print(node)
        node = node.next

def search(head_single : ListNode, val):
    node = head
    while node is not None:
        if node.val == val:
            return node
        node = node.next
    return None


traverse(head_single)

node = search(head_single, 8)
if(node is not None):
    print("found...")
    print(node.val)
else:
    print("not found")


class DoubleNode:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next

    def __str__(self):
        print(str(self.val))


def displayDD(head : DoubleNode):
    node = head
    elements = []
    while node is not None:
        elements.append(node.val)
    
    print("elements: " + str(len(elements)))
    print(" <-> ".join(elements))

print("doubly node")
head = DoubleNode(1)
displayDD(head)


#reverse linked list
def reverse(head : ListNode):
    return head


reverse(head_single)

