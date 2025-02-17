'''
https://leetcode.com/problems/count-complete-tree-nodes
'''
from tree_node import TreeNode
from tree_node import bfs

def count_tree_nodes(root:TreeNode) -> int:
    if not root:
        return 0
    return 1 + count_tree_nodes(root.left) + count_tree_nodes(root.right)
    




#p = [1,2,3,4,5,6]
#Output: true
node_p = TreeNode(1)
node_p.left = TreeNode(2)
node_p.right = TreeNode(3)
node_p.left.left = TreeNode(4)
node_p.left.right = TreeNode(5)
node_p.right.left = TreeNode(6)
result = count_tree_nodes(node_p)
print("count_tree_nodes: " + str(result))


node_p = None
result = count_tree_nodes(node_p)
print("count_tree_nodes: " + str(result))


node_p = TreeNode(1)
result = count_tree_nodes(node_p)
print("count_tree_nodes: " + str(result))


