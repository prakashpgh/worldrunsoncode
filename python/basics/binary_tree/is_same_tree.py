#https://leetcode.com/problems/same-tree/description/

from tree_node import TreeNode
from tree_node import bfs


def is_same_tree(p:TreeNode, q: TreeNode):
    if p is None and q is None:
        return True
    if (p is None and q is not None) or (p is not None and q is None):
        return False
    if p.val != q.val:
        return False
    return is_same_tree(p.left, q.left) and is_same_tree(q.right, q.right)



p = [1,2,3]
q = [1,2,3]
#Output: true
node_p = TreeNode(1)
node_p.left = TreeNode(2)
node_p.right = TreeNode(3)

node_q = TreeNode(1)
node_q.left = TreeNode(2)
node_q.right = TreeNode(3)
same_tree = is_same_tree(node_p, node_q)
print("is_same_tree: " + str(same_tree))


p = [1,2]
q = [1,None,2]
#Output: false
node_p = TreeNode(1)
node_p.left = TreeNode(2)

node_q = TreeNode(1)
node_q.left = None
node_q.right = TreeNode(2)
same_tree = is_same_tree(node_p, node_q)
print("is_same_tree: " + str(same_tree))


p = [1,2,1]
q = [1,1,2]
#Output: false
node_p = TreeNode(1)
node_p.left = TreeNode(2)
node_p.right = TreeNode(1)

node_q = TreeNode(1)
node_q.left = TreeNode(1)
node_q.right = TreeNode(2)
same_tree = is_same_tree(node_p, node_q)
print("is_same_tree: " + str(same_tree))
