'''
https://leetcode.com/problems/merge-k-sorted-lists/

Approach I:
    compare the heads of each of the k-lists and either create a new list or create in-place

Approach II:
    create a HeapNode which wraps ListNode
    heappush the heads of the k-lists

    heap pop till the heap is empty
        get the ListNode from the HeapNode
        append to the result
        push the next of that node into the heap

'''
import sys
import heapq

class ListNode:
    def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class HeapNode:
    def __init__(self, node:ListNode):
        self.node = node
        print("heapnode: " + str(type(node)))

    def __lt__(self, other):
        return self.node.val < other.node.val


def merge_k_sorted_lists(lists: list[ListNode]) -> list[ListNode]:
    result = ListNode()
    result_curr = result
    heap = []

    #push from the heads from lists into heap
    print("lists-type" + str(lists))
    for l in lists:
        #print("l-type val" + l.val)
        #print("l-type" + str(type(l)))
        if l:
            heapq.heappush(heap, HeapNode(l))

    while heap:
        heap_node = heapq.heappop(heap)
        node = heap_node.node
        if not node:
            continue
        result_curr.next = node
        result_curr = node
        node = node.next
        if node:
            heapq.heappush(heap, HeapNode(node))

    return result.next



#lists = [[1,4,5],[1,3,4],[2,6]]
#Output: [1,1,2,3,4,4,5,6]
lists = []
a = ListNode(1)
a.next = ListNode(4)
a.next.next = ListNode(5)
lists.append(a)

a = ListNode(1)
a.next = ListNode(3)
a.next.next = ListNode(4)
lists.append(a)

a = ListNode(2)
a.next = ListNode(6)
lists.append(a)

result = merge_k_sorted_lists(lists)
print("result: " + str(result))
node = result
nodes = []
while node:
    nodes.append(str(node.val))
    node = node.next
print("result:" + ",".join(nodes))
    



lists = []
#Output: []


lists = [[]]
