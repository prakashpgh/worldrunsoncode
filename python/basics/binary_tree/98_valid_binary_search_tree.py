'''
https://leetcode.com/problems/validate-binary-search-tree/description/

https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

left is smaller than root
right is greater than root
each key must be distinct

time: O(N) => visiting nodes once
space: O(H) => dfs stack space.
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque
import sys

#mistake.
def validate_binary_search_tree(root: TreeNode):
    def validate_bst(node: TreeNode, min_val, max_val):
        if not node:
            return True
        if node.val <= min_val or node.val >= max_val:
            return False
                
        return validate_bst(node.left, min_val, node.val) and validate_bst(node.right, node.val, max_val)
    return validate_bst(root, float('-inf'), float('inf'))


#[5,4,6,null,null,3,7]
#false
node_root = TreeNode(5)
node_root.left = TreeNode(4)
node_root.right = TreeNode(6)
node_root.left.left = None
node_root.left.right = None
node_root.right.left = TreeNode(3)
node_root.right.right = TreeNode(7)
result = validate_binary_search_tree(node_root)
print("bst_minimum_absolute_difference: " + str(result))



#Input: root = [2,2,2]
#Output: false
node_root = TreeNode(2)
node_root.left = TreeNode(2)
node_root.right = TreeNode(2)
result = validate_binary_search_tree(node_root)
print("bst_minimum_absolute_difference: " + str(result))



#Input: root = [2,1,3]
#Output: true
node_root = TreeNode(2)
node_root.left = TreeNode(1)
node_root.right = TreeNode(3)
result = validate_binary_search_tree(node_root)
print("bst_minimum_absolute_difference: " + str(result))



#Input: root = [5,1,4,null,null,3,6]
#Output: false
node_root = TreeNode(5)
node_root.left = TreeNode(1)
node_root.right = TreeNode(4)
node_root.left.left = None
node_root.left.right = None
node_root.right.left = TreeNode(3)
node_root.right.right = TreeNode(6)
result = validate_binary_search_tree(node_root)
print("bst_minimum_absolute_difference: " + str(result))
