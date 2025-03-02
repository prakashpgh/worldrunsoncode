'''
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

1) if root val === p or q, then root is the lca

1) search left root , right root.
    if both return then passed node

    if both return valid nodes, then return the passed node.
    else if left,left, or rigt
    
    return the search when you find eithe p or q

#meta
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque
import sys




def lca(root: TreeNode, p: TreeNode, q: TreeNode):
    if not root:
        return None
    
    if root.val == p.val or root.val == q.val:
        return root
    
    left = lca(root.left, p, q)
    right = lca(root.right, p, q)
    
    if left and right:
        return root
    if left:
        return left
    else:
        return right



root = [6,2,8,0,4,7,9,None,None,3,5]
p = 2
q = 8
#Output: 6
node_root = TreeNode(6)
node_root.left = TreeNode(2)
p = node_root.left
node_root.right = TreeNode(8)
q = node_root.right
node_root.left.left = TreeNode(0)
node_root.left.right = TreeNode(4)
node_root.right.left = TreeNode(7)
node_root.right.right = TreeNode(9)
node_root.left.left.left = None
node_root.left.left.right = None
node_root.left.right.left = TreeNode(3)
node_root.left.right.right = TreeNode(5)


result = lca(node_root, p, q)
print("lca: " + str(result))


#root = [6,2,8,0,4,7,9,None,None,3,5]
#p = 2
#q = 4
#Output: 2
node_root = TreeNode(6)
node_root.left = TreeNode(2)
p = node_root.left
node_root.right = TreeNode(8)

node_root.left.left = TreeNode(0)
node_root.left.right = TreeNode(4)
q = node_root.left.right
node_root.right.left = TreeNode(7)
node_root.right.right = TreeNode(9)
node_root.left.left.left = None
node_root.left.left.right = None
node_root.left.right.left = TreeNode(3)
node_root.left.right.right = TreeNode(5)

result = lca(node_root, p, q)
print("lca: " + str(result))


#root = [2,1]
#p = 2
#q = 1
#Output: 2
node_root = TreeNode(2)
p = node_root
node_root.left = TreeNode(1)
q = node_root.left

result = lca(node_root, p, q)
print("lca: " + str(result))
