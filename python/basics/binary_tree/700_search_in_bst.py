'''
https://leetcode.com/problems/search-in-a-binary-search-tree/

t: O(log N) ... best case, worst case N

s: O(H)
'''

from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def search_bst_recursive(root: TreeNode, val: int) -> TreeNode:
    if not root:
        return None
    if val == root.val:
        return root
    if val < root.val:
        return search_bst_recursive(root.left)
    else:
        return search_bst_recursive(root.right)


def search_bst_iterative(root: TreeNode, val: int) -> TreeNode:
    node = root
    while node:
        if node.val == val:
            break
        if node.val < val:
            node = node.right
        else:
            node = node.left
    return node



