'''
https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

inorder traversal... to get the min. differences will visit the trees inorder in BST
    compare prev and next.. if prev is not None.
        get the min. abs

'''

from tree_node import TreeNode
from tree_node import bfs
from collections import deque
import sys

def bst_minimum_absolute_difference(root: TreeNode):
    if not root:
        return
    prev = [None]
    min_abs_difference = [sys.maxsize]
    def dfs(node: TreeNode):
        if not node:
            return
        
        dfs(node.left)
        if prev[0]:
            min_abs_difference[0] = min(min_abs_difference[0], abs(prev[0] - node.val))
        prev[0] = node.val

        dfs(node.right)

    dfs(root)
    return min_abs_difference[0]


node_root = TreeNode(20)
node_root.left = TreeNode(15)
node_root.right = TreeNode(25)
node_root.left.left = TreeNode(7)
node_root.left.right = TreeNode(17)
node_root.right.left = TreeNode(22)
result = bst_minimum_absolute_difference(node_root)
print("bst_minimum_absolute_difference: " + str(result))



#root = [4,2,6,1,3]
#Output: 1
node_root = TreeNode(4)
node_root.left = TreeNode(2)
node_root.right = TreeNode(6)
node_root.left.left = TreeNode(1)
node_root.left.right = TreeNode(3)
result = bst_minimum_absolute_difference(node_root)
print("bst_minimum_absolute_difference: " + str(result))



#root = [1,0,48,None, None,12,49]
#Output: 1
node_root = TreeNode(1)
node_root.left = TreeNode(0)
node_root.right = TreeNode(48)
node_root.left.left = None
node_root.left.right = None
node_root.right.left = TreeNode(12)
node_root.right.right = TreeNode(49)
result = bst_minimum_absolute_difference(node_root)
print("bst_minimum_absolute_difference: " + str(result))

