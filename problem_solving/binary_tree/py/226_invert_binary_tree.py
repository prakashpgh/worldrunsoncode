'''
https://leetcode.com/problems/invert-binary-tree
swap the right and left trees

Approach II: Iterative.. use q
https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
'''
from tree_node import TreeNode
from tree_node import bfs

def invert_binary_tree(root):
    if not root:
        return
    tmp = root.right
    root.right = root.left
    root.left = tmp
    invert_binary_tree(root.left)
    invert_binary_tree(root.right)
    return root


def invert_binary_tree


root = [4,2,7,1,3,6,9]
#[4,7,2,9,6,3,1]


node = TreeNode(4)
node.left = TreeNode(2)
node.left.left = TreeNode(1)
node.left.right = TreeNode(3)
node.right = TreeNode(7)
node.right.left = TreeNode(6)
node.right.right = TreeNode(9)
s = bfs(node)
print("s=" + s)

inverted = invert_binary_tree(node)
s = bfs(inverted)
print("s-inverted = " + s)


#root = [2,1,3]
#Output: [2,3,1]
node = TreeNode(2)
node.left = TreeNode(1)
node.right = TreeNode(3)
inverted = invert_binary_tree(node)
s = bfs(inverted)
print("s-inverted = " + s)


root = []
Output: []
node = None
inverted = invert_binary_tree(node)
s = bfs(inverted)
print("s-inverted = " + s)
