'''
https://leetcode.com/problems/binary-tree-vertical-order-traversal/

do a bfs..
in the q, add node,0

    for left node add col-1. 
    for right node, add col+1

    sort the colmap[col_index, node_value], get map[index]
'''

from tree_node import TreeNode
from tree_node import bfs
from collections import deque
from collections import defaultdict

def vertical_order_traversal(root: TreeNode) -> list[list[int]]:
    if not root:
        return []
    q = deque()
    q.append([root, 0])
    column_map = defaultdict(list)

    while q:
        [node, col] = q.popleft()
        if not node:
            continue
        column_map[col].append(node.val)
        if node.left:
            q.append([node.left, col -1])
        if node.right:
            q.append([node.right, col+1])
    return [ column_map[col] for col in sorted(column_map.keys())]


node_root = TreeNode(3)
node_root.left = TreeNode(9)
node_root.right = TreeNode(20)
node_root.right.left = TreeNode(15)
node_root.right.right = TreeNode(7)
result = vertical_order_traversal(node_root)
print("vertical_order_traversal: " + str(result))



