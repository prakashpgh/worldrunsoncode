class ListNode:
    def __init__(self, val, next=None, random=None):
        self.val = val
        self.next = next
        self.random = random

    def __str__(self):
        return str(self.val)
    
    def traverse(self, mem_location=False):
        #print("traverse linkedlist")
        #print(self.val)
        node = self
        str_list = []
        while node:
            #print(node.val)
            if mem_location:
                str_list.append(str(node.val) + " ml:" + str(id(node)) + "->")
            else:
                str_list.append(str(node.val) + "->")
            node = node.next
        #print("str_list: " + str(str_list))
        return "".join(str_list)


class DoubleNode:
    def __init__(self, val, prev=None, next=None):
        self.val = val
        self._prev = prev
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


def traverse(node : ListNode):
    print("traverse call...")
    while(node is not None):
        print(node)
        node = node.next

