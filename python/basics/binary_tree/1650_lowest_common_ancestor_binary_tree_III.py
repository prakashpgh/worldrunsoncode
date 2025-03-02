'''
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/

given parent of the 2 nodes - find the lca
'''

from tree_node import TreeNode
from tree_node import bfs


class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None


def lowest_common_ancestor_binary_tree(p: 'Node', q: 'Node') -> 'Node':
    if p is None or q is None:
        return None
    if p == q:
        return p
    if p == q:
        return p
    else:
        parent = lowest_common_ancestor_binary_tree(p, q.parent)
        if not parent:
            parent = lowest_common_ancestor_binary_tree(p.parent, q)
        else:
            parent = lowest_common_ancestor_binary_tree(p.parent, q.parent)
        return parent
    return None



node = Node(3)
node.parent = None
node.left = Node(5)
node.left.parent = node
p = node.left
node.right = Node(1)
node.right.parent = node
q = node.right
node.left.left = Node(6)
node.left.left.parent = node.left
node.left.right = Node(2)
node.left.right.parent = node.left
node.right.left = Node(0)
node.right.left.parent = node.right
node.right.right = Node(8)
node.right.right.parent = node.right

node.left.left.left = None
node.left.left.right = None
node.left.right.left = Node(7)
node.left.right.left.parent = node.left.right
node.left.right.right = Node(4)
node.left.right.right.parent = node.left.right

parent = lowest_common_ancestor_binary_tree(p, q)
if parent:
    print("parent=" + str(parent.val))

q=node.left.right.right 
parent = lowest_common_ancestor_binary_tree(p, q)
if parent:
    print("parent=" + str(parent.val))



root = [3,5,1,6,2,0,8,None,None,7,4]
p = 5
q = 4