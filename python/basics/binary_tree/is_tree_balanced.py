#https://leetcode.com/problems/balanced-binary-tree/description/

from tree_node import TreeNode
from tree_node import bfs

def is_tree_balanced(root: TreeNode):
    balanced = [True]

    def height(root):
        if not root:
            return 0
        left_height = height(root.left)
        val = 0
        if root.left:
            val = root.left.val
        #print("left_height: " + str(val)+ " => " + str(left_height) )
        right_height = height(root.right)
        val = 0
        if root.right:
            val = root.right.val
        #print("right_height: " + str(val) + " => " + str(right_height) )
        if abs(left_height - right_height) > 1:
            balanced[0] = False
        return 1 + max(left_height,right_height)

    height(root)
    #print("is_tree_balanced: " + str(balanced[0]))
    return balanced[0]

root = [3,9,20,None, None,15,7]
#Output: 3
node = TreeNode(3)
node.left = TreeNode(9)
node.right = TreeNode(20)
node.left.left = None
node.left.right = None
node.right.left = TreeNode(15)
node.right.right = TreeNode(7)
s = bfs(node)
print("s=" + s)
is_balanced = is_tree_balanced(node)
print("is_balanced: " + str(is_balanced))


#root = [1,2,2,3,3,null,null,4,4]
#Output: false
node = TreeNode(1)
node.left = TreeNode(2)
node.right = TreeNode(2)
node.left.left = TreeNode(3)
node.left.right = TreeNode(3)
node.right.left = None
node.right.right = None
node.left.left.left = TreeNode(4)
node.left.left.right = TreeNode(4)
s = bfs(node)
print("s=" + s)
is_balanced = is_tree_balanced(node)
print("is_balanced: " + str(is_balanced))

