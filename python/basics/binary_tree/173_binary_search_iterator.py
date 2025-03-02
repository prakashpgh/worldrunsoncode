'''
https://leetcode.com/problems/binary-search-tree-iterator/?envType=study-plan-v2&envId=top-interview-150

#maintain an array, in the init, do an inorder traversal, and fill the array.
maintain an index...of where the iterator is in the traversal
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque



class BSTIterator:

    def __init__(self, root: TreeNode):
        self.data = []
        self.index = -1
        self.inorder(root)

    def inorder(self, root: TreeNode()):
        if not root:
            return None
        self.inorder(root.left)
        self.data.append(root.val)
        self.inorder(root.right)

    def next(self) -> int:
        self.index += 1
        if self.index >= len(self.data):
            return None
        return self.data[self.index]

    def hasNext(self) -> bool:
        return len(self.data) > self.index + 1