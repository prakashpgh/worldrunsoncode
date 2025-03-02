'''
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

https://www.geeksforgeeks.org/connect-nodes-at-same-level/

Idea: 
    inorder traversal... and connect the nodes at the same level

'''
#todo
from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def populate_next_right_pointers(root: TreeNode):
    if not root:
        return None
    q = deque()
    q.append(root)
    while q:
        l = len(q)
        prev = None
        for _ in range(l):
            node = q.popleft()
            if prev:
                prev.next = node
            prev = node
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)



node = TreeNode(1)
node.left = TreeNode(2)
node.right = TreeNode(3)
node.left.left = TreeNode(4)
node.left.right = TreeNode(5)
node.right.left = None
node.right.right = TreeNode(7)
s = bfs(node)
print("s=" + s)
populate_next_right_pointers(node)
print("after s=" + bfs(node))
