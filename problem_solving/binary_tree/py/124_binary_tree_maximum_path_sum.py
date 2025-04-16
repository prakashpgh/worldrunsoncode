'''
https://leetcode.com/problems/binary-tree-maximum-path-sum

#mistake got this wrong
'''

from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def binary_tree_maximum_path_sum(root: TreeNode):
    max_sum = []
    if root:
        max_sum.append(root.val)

    def max_path_sum(node):
        if not node:
            return 0
        
        lval = max(0,max_path_sum(node.left))
        rval = max(0,max_path_sum(node.right))
        
        max_sum[0] = max( max_sum[0], node.val + lval + rval)
        gain_from_node= node.val + max(lval, rval)  #mistake this is is bit difficult to understand... it gives the gain from this node.
                                                    #
        return gain_from_node
    
    max_path_sum(root)
    return max_sum[0]


node_root = TreeNode(-2)
node_root.left = TreeNode(-3)
node_root.right = TreeNode(5)
node_root.left.left = TreeNode(2)
node_root.left.right = TreeNode(-1)
node_root.right.left = TreeNode(1)
node_root.right.right = TreeNode(2)
result = binary_tree_maximum_path_sum(node_root)
print(f"resullt: {result}")
