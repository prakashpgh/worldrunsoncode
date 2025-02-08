#https://leetcode.com/problems/binary-tree-level-order-traversal/description/
'''
here its BFS, only difference is that the elements in a particular level are grouped together
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def level_order_traversal(root : TreeNode) -> list[list[int]]:
    if not root:
        return []
    q = deque()
    q.append(root)
    result = []
    while q:
        l = len(q)
        level =[]
        for i in range(l):
            node = q.popleft()
            level.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        result.append(level)
    return result



#root = [3,9,20,null,null,15,7]
#Output: [[3],[9,20],[15,7]]
node_root = TreeNode(3)
node_root.left = TreeNode(9)
node_root.right = TreeNode(20)
node_root.left.left = None
node_root.left.right = None
node_root.right.left = TreeNode(15)
node_root.right.right = TreeNode(7)
result = level_order_traversal(node_root)
print("level_order_traversal: " + str(result))


#root = [1]
#Output: [[1]]
node_root = TreeNode(1)
result = level_order_traversal(node_root)
print("level_order_traversal: " + str(result))


#Input: root = []
#Output: []
node_root = None
result = level_order_traversal(node_root)
print("level_order_traversal: " + str(result))
