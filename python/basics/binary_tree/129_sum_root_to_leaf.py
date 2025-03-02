'''
https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=study-plan-v2&envId=top-interview-150

Idea:
    dfs using iterative stack
    in the stack, store (node,curr.num)
    curr_num*10 + node.val
        if its the leaf, add to the total.
        else, add the right and left nodes to stack
'''

from tree_node import TreeNode
from tree_node import bfs
from collections import deque
import sys


def sum_root_to_leaf(root: TreeNode) -> int:
    if not root:
        return 0
    stack = [(root, 0)]
    total = 0
    while stack:
        root, sum = stack.pop()
        if root:
            sum = sum*10 + root.val
            if not root.left and not root.right:
                total += sum
            if root.left:
                stack.append((root.left, sum))
            if root.right:
                stack.append((root.right, sum))
    return total



#root = [1,2,3]
#Output: 25
node_root = TreeNode(1)
node_root.left = TreeNode(2)
node_root.right = TreeNode(3)
result = sum_root_to_leaf(node_root)
print("result: " + str(result))

root = [4,9,0,5,1]
#Output: 1026
node_root = TreeNode(4)
node_root.left = TreeNode(9)
node_root.right = TreeNode(0)
node_root.left.left = TreeNode(5)
node_root.left.right = TreeNode(1)
result = sum_root_to_leaf(node_root)
print("result: " + str(result))

