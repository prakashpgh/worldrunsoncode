'''
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque
import sys


def bst_lowest_common_ancestor(root: TreeNode, p: TreeNode, q: TreeNode):
    lca = [root]  #start with root

    def search(node: TreeNode):
        if not node:
            return
        lca[0] = node
        if node is p or node is q:
            return  #nothing better.
        elif node.val < p.val and node.val < q.val:
            search(node.right)
        elif node.val > p.val and node.val > q.val:
            search(node.left)
        else:
            return
    
    search(root)
    return lca[0]




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


result = bst_lowest_common_ancestor(node_root, p, q)
print("bst_lowest_common_ancestor: " + str(result))


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
result = bst_lowest_common_ancestor(node_root, p, q)
print("bst_lowest_common_ancestor: " + str(result))



#root = [2,1]
#p = 2
#q = 1
#Output: 2
node_root = TreeNode(2)
p = node_root
node_root.left = TreeNode(1)
q = node_root.left
result = bst_lowest_common_ancestor(node_root, p, q)
print("bst_lowest_common_ancestor: " + str(result))

