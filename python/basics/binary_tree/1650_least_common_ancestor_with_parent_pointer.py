'''
Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/

Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

'''

from tree_node import Node
from tree_node import bfs
from collections import deque


class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None



def least_common_ancestor(p: Node, q: Node) -> Node:
    p1 = p
    p2 = q
    while p1 != p2:
        p1 = p1.parent if p1.parent else q
        p2 = p2.parent if p2.parent else p
    return p1







#root = [3,9,20,null,null,15,7]
#Output: [3.00000,14.50000,11.0000]
node_root = Node(3)
node_root.left = Node(9)
node_root.right = Node(20)
node_root.left.left = None
node_root.left.right = None
node_root.right.left = Node(15)
node_root.right.right = Node(7)
result = average_of_levels(node_root)
print("average_of_levels: " + str(result))
