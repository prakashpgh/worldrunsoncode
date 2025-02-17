class ListNode:
    def __init__(self, val, next=None, random=None):
        self._val = val
        self._next = next
        self._random = random

    def __str__(self):
        return str(self._val)
    
    def traverse(self, mem_location=False):
        #print("traverse linkedlist")
        #print(self._val)
        node = self
        str_list = []
        while node:
            #print(node._val)
            if mem_location:
                str_list.append(str(node._val) + " ml:" + str(id(node)) + "->")
            else:
                str_list.append(str(node._val) + "->")
            node = node._next
        #print("str_list: " + str(str_list))
        return "".join(str_list)


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


def traverse(node : ListNode):
    print("traverse call...")
    while(node is not None):
        print(node)
        node = node._next

