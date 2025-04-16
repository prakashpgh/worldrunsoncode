'''
1372_longest_zigzag_path_in_binary_tree.py

#tricky problem..
need to track, the direction of the previous step,number of steps

case 1) the previous direction was to right, 
            left, step+1
            right, 1  <= new stat
case 2) the previous direction was to left
            right, step+1
            left, 1  <= new stat
case 3) from the root
            left, "left", 1
            right, "right", 1

'''

from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def longest_zigzag_path_in_binary_tree(root: TreeNode):
    longest_path = 0
    def dfs(node, direction, steps):
        nonlocal longest_path
        if not node:
            return 0
        longest_path = max(longest_path, steps)

        if direction == "right":
            dfs( node.left, "left", steps+1)
            dfs( node.right, "right", 1)    
        elif direction == "left":
            dfs( node.right, "right", steps+1)
            dfs( node.left, "left", 1)    
        else:
            dfs(node.left, "left", 1)
            dfs(node.right, "right", 1)

    dfs(root, "", 0)
    return longest_path

