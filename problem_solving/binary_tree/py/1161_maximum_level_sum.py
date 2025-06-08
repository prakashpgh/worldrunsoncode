'''
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def max_level_sum(root: TreeNode) -> int:
    if not root:
        return 0
    q = deque()
    q.append(root)
    max_sum = float('-inf')
    max_level = float('-inf')
    level = 0
    while q:
        sum = 0
        l = len(q)
        level += 1
        for _ in range(l):
            node = q.popleft()
            sum += node.val

            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        if sum > max_sum:
            max_sum = sum
            max_level = level
    return max_level