#https://leetcode.com/problems/subtree-of-another-tree/description/

from tree_node import TreeNode
from tree_node import bfs
from collections import deque

def is_sub_tree(root: TreeNode, sub_tree: TreeNode):

    def same(p:TreeNode, q:TreeNode):
        if not p and not q:
            return True
        if (not p and q) or (not q and p):
            return False
        if p.val != q.val:
            return False
        return same(p.right, q.right) and same(p.left, q.left)

    def bfs_traverse(root_node: TreeNode):
        dq = deque()
        if not root_node:
            return False
        dq.append(root_node)
        hash = set()
        hash.add(root_node)
        while dq:
            node = dq.popleft()
            if not node:
                continue
            dq.append(node.left)
            dq.append(node.right)
            hash.add(node.left)
            hash.add(node.right)
            ret = same(node, sub_tree)
            if ret:
                print ("node:" + bfs(node))
                print ("sub_tree:" + bfs(sub_tree))
                return True 
        return False
    
    return bfs_traverse(root)


#root = [3,4,5,1,2]
subRoot = [4,1,2]
node_root = TreeNode(3)
node_root.left = TreeNode(4)
node_root.right = TreeNode(5)
node_root.left.left = TreeNode(1)
node_root.left.right = TreeNode(2)

node_sub = TreeNode(4)
node_sub.left = TreeNode(1)
node_sub.right = TreeNode(2)
#Output: true
sub_tree = is_sub_tree(node_root, node_sub)
print("is_sub_tree: " + str(sub_tree))


#node_root = [3,4,5,1,2,None,None,None,None,0]
#node_sub = [4,1,2]
node_root = TreeNode(3)
node_root.left = TreeNode(4)
node_root.right = TreeNode(5)
node_root.left.left = TreeNode(1)
node_root.left.right = TreeNode(2)
node_root.right.left = None
node_root.right.right = None
node_root.left.left.left = None
node_root.left.left.right = None
node_root.left.right.left = TreeNode(0)

#Output: false
sub_tree = is_sub_tree(node_root, node_sub)
print("is_sub_tree: " + str(sub_tree))
