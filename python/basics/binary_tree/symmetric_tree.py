#https://leetcode.com/problems/symmetric-tree/
'''
    similar to same, but also checks the left == right,  right == left
    MISTAKE
'''
from tree_node import TreeNode
from tree_node import bfs


def symmetric_tree(root:TreeNode):
    def same(p:TreeNode, q:TreeNode):
        if not p and not q:
            return True
        if (not p or not q ):
            return False
        if p.val != q.val:
            return False
        return same(p.left, q.right) and same(p.right, q.left)
    return same(root, root)

p = [1,2,2,3,4,4,3]
#Output: true
node_p = TreeNode(1)
node_p.left = TreeNode(2)
node_p.right = TreeNode(2)
node_p.left.left = TreeNode(3)
node_p.left.right = TreeNode(4)
node_p.right.left = TreeNode(4)
node_p.right.right = TreeNode(3)

symmetric = symmetric_tree(node_p)
print("symmetric_tree: " + str(symmetric))


p = [1,2,2,None,3,None,3]
#Output: false
node_p = TreeNode(1)
node_p.left = TreeNode(2)
node_p.right = TreeNode(2)
node_p.left.left = None
node_p.left.right = TreeNode(3)
node_p.right.left = None
node_p.right.right = TreeNode(3)

symmetric = symmetric_tree(node_p)
print("symmetric_tree: " + str(symmetric))


