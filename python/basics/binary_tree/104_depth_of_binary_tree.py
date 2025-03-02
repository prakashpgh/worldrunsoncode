'''
#https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

https://www.geeksforgeeks.org/iterative-method-to-find-height-of-binary-tree/

Approach I:
    recursive.
        1 + max( depth of left node, depth of right node)

Approach II: iterative.
    here we use the Q.
    note to pop the nodes of the same level, take the len(), and iterate the length

#meta
'''
from tree_node import TreeNode
from tree_node import bfs


def depth_of_binary_tree(root:TreeNode):
    if not root:
        return 0
    return 1+max(depth_of_binary_tree(root.left), depth_of_binary_tree(root.right))

from collections import deque
def depth_of_binary_tree_iterative(root:TreeNode):
    if not root:
        return 0
    q = deque()
    q.append(root)
    depth = 0
    while q:
        level_count = len(q)    #mistake
        for _ in range(level_count):
            node = q.popleft()
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        depth += 1
    return depth


root = [3,9,20,None, None,15,7]
#Output: 3
node = TreeNode(3)
node.left = TreeNode(9)
node.right = TreeNode(20)
node.left.left = None
node.left.right = None
node.right.left = TreeNode(15)
node.right.right = TreeNode(7)
s = bfs(node)
print("s=" + s)
depth = depth_of_binary_tree(node)
print("depth=" + str(depth))

depth = depth_of_binary_tree_iterative(node)
print("depth_of_binary_tree_iterative=" + str(depth))



root = [1,None,2]
#Output: 2
node = TreeNode(1)
node.left = None
node.right = TreeNode(2)
s = bfs(node)
print("s=" + s)
depth = depth_of_binary_tree(node)
print("depth=" + str(depth))

depth = depth_of_binary_tree_iterative(node)
print("depth_of_binary_tree_iterative=" + str(depth))
