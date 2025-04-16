'''
flatten_multilevel_double_linklist
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

look for node where child is not null
    apply the recursive to the child

    set up links between current and the child.. next and prev
    set up links between saved next and the child tail.

O(N)
O(1)
'''

class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


from linkedlist import ListNode



def flatten(head: "Node") -> "Node":

    def flatten_dfs(node: "Node"):
        current = node
        tail = node
        while current:
            next_node = current.next
            if current.child:
                child_tail = flatten_dfs(current.child)
                current.next = current.child
                current.child.prev = current
                current.child = None

                if next_node:
                    child_tail.next = next_node
                    next_node.prev = child_tail

                tail = child_tail
                current = next_node
            else:
                tail = current
                current = current.next
        return tail        
        
    if not head:
        return None
    flatten_dfs(head)
    return head


    


