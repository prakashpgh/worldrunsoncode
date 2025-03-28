'''
minimum_path_sum.py
'''

from tree_node import TreeNode
from tree_node import bfs


def minimum_path_sum(root: TreeNode):
    min_path = [float('inf')]

    def dfs(node: TreeNode, sum: float):
        if not node:
            return 0
        if (not node.left) and (not node.right):
            min_path[0]=min(min_path[0], sum)
            return
        if node.left:
            dfs(node.left, sum + node.left.val)
        if node.right:
            dfs(node.right, sum + node.right.val)
    
    if not root:
        return 0
    
    dfs(root, root.val)
    return min_path[0]





node = TreeNode(10)
node.left = TreeNode(5)
node.right = TreeNode(15)
node.left.left = TreeNode(3)
node.left.right = TreeNode(8)
node.right.right = TreeNode(1)
s = bfs(node)
print("s=" + s)
path_sum = minimum_path_sum(node)
print("minimum_path_sum: " + str(path_sum))



node = TreeNode(10)
node.left = TreeNode(5)
node.right = TreeNode(5)
node.left.right = TreeNode(2)
node.right.right = TreeNode(1)
node.right.right.left = TreeNode(-1)
s = bfs(node)
print("s=" + s)
path_sum = minimum_path_sum(node)
print("minimum_path_sum: " + str(path_sum))

    