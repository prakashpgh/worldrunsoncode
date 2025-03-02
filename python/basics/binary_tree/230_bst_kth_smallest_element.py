#https://leetcode.com/problems/kth-smallest-element-in-a-bst/
'''
in-order dfs gives in the sorted order for BST

Idea:
    do dfs on the l-node, then the r-node..  check for the kth element

    recursive: left, node, right
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque

def kth_smallest_element(root: TreeNode, k: int)->int:
    if not root:
        return
    ans =[]
    stk = []
    curr = root
    index = 0
    while curr or len(stk) > 0:
        #reach the left most node of the curr node
        while curr: 
            stk.append(curr)
            curr = curr.left
        curr = stk.pop()
        if index == k-1:
            return curr.val
        index += 1

        curr = curr.right



def kth_smallest_element_recursive(root: TreeNode, k: int)->int:
    index = [k]
    ans = []
    def dfs(node: TreeNode):
        if not node:
            return
        
        dfs(node.left)

        if index[0] == 1:
            ans.append(node.val)
        index[0] -= 1

        if index[0] > 0:
            dfs(node.right) 

    dfs(root)
    return ans[0]

#root = [5,3,6,2,4,null,null,1]
k = 3
#Output: 3
node_root = TreeNode(5)
node_root.left = TreeNode(3)
node_root.right = TreeNode(6)
node_root.left.left = TreeNode(2)
node_root.left.right = TreeNode(4)
node_root.left.left.left = TreeNode(1)
result = kth_smallest_element(node_root, k)
print("kth_smallest_element: " + str(result))

result = kth_smallest_element_recursive(node_root, k)
print("kth_smallest_element recursive: " + str(result))



#root = [3,1,4,null,2]
k = 1
#Output: 1
node_root = TreeNode(3)
node_root.left = TreeNode(1)
node_root.right = TreeNode(4)
node_root.left.left = None
node_root.left.right = TreeNode(2)
result = kth_smallest_element(node_root, k)
print("kth_smallest_element: " + str(result))

result = kth_smallest_element_recursive(node_root, k)
print("kth_smallest_element recursive: " + str(result))





