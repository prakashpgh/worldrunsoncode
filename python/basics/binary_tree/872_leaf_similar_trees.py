'''
https://leetcode.com/problems/leaf-similar-trees/

dfs.. and append the leaf nodes

t: O(n1 + n2)   => we visit each node atleast onc
s: O(n1 + n2) => recursion.. height + store the leaves (N/2 + 1) leaves
'''

from tree_node import TreeNode
from tree_node import bfs


def leaf_similar_trees(root1:TreeNode, root2:TreeNode) -> bool:
    
    def leaf_nodes(node: TreeNode, list_nodes: list[int]):
        if not node:
            return
        if not node.left and not node.right:
            list_nodes.append(node.val)
            return
        leaf_nodes(node.left, list_nodes)
        leaf_nodes(node.right, list_nodes)
    a1 = []
    a2 = []
    leaf_nodes(root1, a1)
    leaf_nodes(root2, a2)
    return a1==a2

