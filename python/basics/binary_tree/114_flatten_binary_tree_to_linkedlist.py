'''
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/?ref=gcse_outind
https://www.youtube.com/watch?v=vssbwPkarPQ
Idea:
    put the root on stack.
    while stack empty, 
        pop, 
        push right, 
        push left.
        peek.
        the right of current should point to the left node(peek)
        left of current should be None
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def flatten_binary_tree_to_linkedlist(root:TreeNode):
    stack = []
    if not root:
        return None
    stack.append(root)
    while stack:
        node = stack.pop()
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)
        if stack:
            node.right = stack[len(stack)-1]
        node.left = None
    return root



node_root = TreeNode(1)
node_root.left = TreeNode(2)
node_root.right = TreeNode(5)
node_root.left.left = TreeNode(3)
node_root.left.right = TreeNode(4)
node_root.right.right = TreeNode(6)

root = flatten_binary_tree_to_linkedlist(node_root)
print("result: " + str(root))