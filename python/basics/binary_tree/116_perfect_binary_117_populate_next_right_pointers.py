'''
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/  => 116 perfect binary tree
for perfect binary tree, you dont need additional storage

    while loop => to traverse levels
        while loop => to traverse the nodes in a given level




https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

https://www.geeksforgeeks.org/connect-nodes-at-same-level/

Idea: 
    inorder traversal... and connect the nodes at the same level

'''
#todo
from tree_node import TreeNode
from tree_node import bfs
from collections import deque


#no need of extra storage here..
def populate_next_right_perfect_binary_tree(root: TreeNode) -> TreeNode:
    #todo
    pass


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
