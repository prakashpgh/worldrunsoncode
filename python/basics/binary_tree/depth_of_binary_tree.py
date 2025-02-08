#https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
from tree_node import TreeNode
from tree_node import bfs


def depth_of_binary_tree(root:TreeNode):
    if not root:
        return 0
    return 1+max(depth_of_binary_tree(root.left), depth_of_binary_tree(root.right))




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

root = [1,None,2]
#Output: 2
node = TreeNode(1)
node.left = None
node.right = TreeNode(2)
s = bfs(node)
print("s=" + s)
depth = depth_of_binary_tree(node)
print("depth=" + str(depth))
