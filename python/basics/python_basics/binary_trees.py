#bfs on binary tree..
from tree_node import TreeNode
from tree_node import bfs
from collections import deque

#bfs - in level traversal..
#gives all the nodes at a particular level
def bfs_binary_tree(root: TreeNode):
    q = deque()
    q.append(root)
    while q:
        l = len(q)
        for _ in range(l):
            node = q.popleft()
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)


