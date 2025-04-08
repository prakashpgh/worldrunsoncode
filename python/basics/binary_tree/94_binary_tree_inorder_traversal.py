'''
https://leetcode.com/problems/binary-tree-inorder-traversal/
'''

from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def binary_tree_inorder_traversal(root: TreeNode):
    result = []

    def recurse(node):
        if not node:
            return
        recurse(node.left)
        result.append(node.val)
        recurse(node.right)
    recurse(root)
    return result


def binary_tree_inorder_iterative(root: TreeNode):
    result = []
    current = root
    stack =[]
    while current or stack:
        #keep appending the left most in the stack
        while current:
            stack.append(current)
            current = current.left

            current = stack.pop()
            result.append(current.val)
            current = current.right

    return result



node_root = TreeNode(1)
node_root.left = None
node_root.right = TreeNode(2)
node_root.right.left = TreeNode(3)
result = binary_tree_inorder_traversal(node_root)
print("binary_tree_inorder_traversal: " + str(result))
