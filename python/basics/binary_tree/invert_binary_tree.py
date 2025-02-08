from tree_node import TreeNode
from tree_node import bfs

def invert_binary_tree(root):
    if not root:
        return
    tmp = root._right
    root._right = root._left
    root._left = tmp
    invert_binary_tree(root._left)
    invert_binary_tree(root._right)
    return root


root = [4,2,7,1,3,6,9]
#[4,7,2,9,6,3,1]


node = TreeNode(4)
node._left = TreeNode(2)
node._left._left = TreeNode(1)
node._left._right = TreeNode(3)
node._right = TreeNode(7)
node._right._left = TreeNode(6)
node._right._right = TreeNode(9)
s = bfs(node)
print("s=" + s)

inverted = invert_binary_tree(node)
s = bfs(inverted)
print("s-inverted = " + s)


#root = [2,1,3]
#Output: [2,3,1]
node = TreeNode(2)
node._left = TreeNode(1)
node._right = TreeNode(3)
inverted = invert_binary_tree(node)
s = bfs(inverted)
print("s-inverted = " + s)


root = []
Output: []
node = None
inverted = invert_binary_tree(node)
s = bfs(inverted)
print("s-inverted = " + s)
