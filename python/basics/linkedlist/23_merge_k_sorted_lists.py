'''
https://leetcode.com/problems/merge-k-sorted-lists

Approach 1) brute force, put it in an array => sort array, => linkedlist
                time: (N logN)
                space O(N)

Approach 2)  one by one comparison
                O(k N)
                O(n) => LL cost

Approach 3) similar to approach 1, but uses Heap
                O( N logK)
                O(k)
        HeapData  _lt_ 
            


Approach 4) merge lists one by one
    merge 2 lists and form the result
    merge the result with the 3rd list... so on
        time: O(N logK)
        space: O(1)


Approach 5) merge in pairs...  
    time: O(N logK)
    space: O(1)
'''

from linkedlist import ListNode


def merge_2_lists(list1: ListNode, list2: ListNode) -> ListNode:
    result = ListNode(0)
    result_node = result
    node_1 = list1
    node_2 = list2
    while node_1 and node_2:
        if node_1.val <= node_2.val:
            result_node.next = node_1
            node_1 = node_1.next
        elif node_2.val < node_1.val:
            result_node.next = node_2
            node_2 = node_2.next
        result_node = result_node.next
    if node_1:
        result_node.next = node_1
    elif node_2:
        result_node.next = node_2
    return result.next


def merge_k_sorted_convert_list_sort_LL(lists: list[ListNode]) -> ListNode:
    arr = []
    result = ListNode(0)
    result_node = result
    for l in lists:
        while l:
            arr.append(l.val)
            l = l.next
    arr.sort()
    for n in arr:
        result_node.next = ListNode(n)
        result_node = result_node.next
    return result.next


def merge_k_sorted_convert_list_Using_Heap(lists: list[ListNode]) -> ListNode:
    arr = []
    result = ListNode(0)
    result_node = result
    for l in lists:
        while l:
            arr.append(l.val)
            l = l.next
    arr.sort()
    for n in arr:
        result_node.next = ListNode(n)
        result_node = result_node.next
    return result.next




#merging one list at a time.
def merge_k_sorted_lists_one_at_a_time(lists: list[ListNode]) -> ListNode:
    result = None
    N = len(lists)
    if lists:
        result = lists[0]

    for i in range(1, N):
        result = merge_2_lists(result, lists[i])
    return result




def get_data():
    #lists = [[1,4,5],[1,3,4],[2,6]]
    #Output: [1,1,2,3,4,4,5,6]
    A = ListNode(1)
    B = ListNode(4)
    C = ListNode(5)
    A.next = B
    B.next = C
    print( "traverse: " + A.traverse())
    A1 = ListNode(1)
    B1 = ListNode(3)
    C1 = ListNode(4)
    A1.next = B1
    B1.next = C1
    print( "traverse: " + A1.traverse())
    A2 = ListNode(2)
    B2 = ListNode(6)
    A2.next = B2
    print( "traverse: " + A2.traverse())
    return [A, A1, A2]

result = merge_k_sorted_lists_one_at_a_time(get_data())
print("result: " + str(result) + " traverse: " + result.traverse())

result = merge_k_sorted_convert_list_sort_LL(get_data())
print("merge_k_sorted_convert_list_sort_LL: " + str(result) + " traverse: " + result.traverse())





lists = []
#Output: []


lists = [[]]
#Output: []