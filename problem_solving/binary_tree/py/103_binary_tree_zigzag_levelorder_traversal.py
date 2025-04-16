'''
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
binary_tree_zigzag_levelorder_traversal.py

use of BFS...
    add the nodes at each level...
    you can reverse the nodes at alternating layer
    keep a flag to alternate.... reverse the list
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque

def zigzagLevelOrder(root: TreeNode) -> list[list[int]]:
    if not root:
        return []
    q = deque()
    q.append(root)
    result = []
    right_left = True
    while q:
        length = len(q)
        level = []
        for _ in range(length):
            node = q.popleft()
            level.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        if not right_left:
            level.reverse()
        result.append(level)
        right_left = not right_left
    return result    


node_root = TreeNode(3)
node_root.left = TreeNode(9)
node_root.right = TreeNode(20)
node_root.left.left = None
node_root.left.right = None
node_root.right.left = TreeNode(15)
node_root.right.right = TreeNode(7)
result = zigzagLevelOrder(node_root)
print("result: " + str(result))

