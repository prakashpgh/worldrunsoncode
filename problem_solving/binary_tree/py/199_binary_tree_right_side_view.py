'''
https://leetcode.com/problems/binary-tree-right-side-view

idea:
    do a bfs using queue, and at each level, get the last element

#meta
'''

from tree_node import TreeNode
from tree_node import bfs
from collections import deque

def rightSideView(root: TreeNode) -> list[int]:
    if not root:
        return []
    q = deque()
    q.append(root)
    result = []
    while q:
        length = len(q)
        prev = None
        for _ in range(length):
            node = q.popleft()
            if node:
                prev = node
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        if prev:
            result.append(prev.val)
    return result        
