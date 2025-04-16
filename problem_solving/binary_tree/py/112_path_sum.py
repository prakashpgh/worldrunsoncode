'''
#https://leetcode.com/problems/path-sum/

keep traversing the tree... till you encounter the leaf node... and check the target-sum
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def path_sum(root: TreeNode, targetSum: int):
    def has_sum( node: TreeNode, curr_sum: int):
        if not node:
            return False
        #is it leaf node and curr_sum + node value 
        curr_sum += node.val
        if not node.left and not node.right and curr_sum == targetSum:
            return True
        return has_sum(node.left, curr_sum) or has_sum(node.right, curr_sum)

    return has_sum(root, 0)





#root = [5,4,8,11,null,13,4,7,2,null,null,null,1]
#targetSum = 22
#Output: true
node_root = TreeNode(5)
node_root.left = TreeNode(4)
node_root.right = TreeNode(8)
node_root.left.left = TreeNode(11)
node_root.left.right = None
node_root.left.left.left = TreeNode(7)
node_root.left.left.right = TreeNode(2)

node_root.right.left = TreeNode(13)
node_root.right.right = TreeNode(4)
node_root.right.right.right = TreeNode(1)
ret =path_sum(node_root, 22)
print("path_sum: " + str(ret))

#root = [1,2,3]
# targetSum = 5
#Output: false
#(1 --> 2): The sum is 3.
#(1 --> 3): The sum is 4.
node_root = TreeNode(1)
node_root.left = TreeNode(2)
node_root.right = TreeNode(3)
ret =path_sum(node_root, 5)
print("path_sum: " + str(ret))


#root = []
#targetSum = 0
#Output: false
node_root = None
ret =path_sum(node_root, 0)
print("path_sum: " + str(ret))
