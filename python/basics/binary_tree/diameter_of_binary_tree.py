'''
#https://leetcode.com/problems/diameter-of-binary-tree/description/

longest diameter at a given node = diam of left node + diam of right node

max(l, r) + 1 => what this node will contribute to the recursion.


#meta
'''

from tree_node import TreeNode
from tree_node import bfs

def diameter_of_binary_tree(root: TreeNode):
    largest_diameter = [0]
    
    def height(node: TreeNode):
        if not node:
            return 0
        l = height(node.left)
        r = height(node.right)
        largest_diameter[0] = max(largest_diameter[0], l+r)
        return 1 + max(l, r)
    height(root)
    
    return largest_diameter[0]

    


root = [1,2,3,4,5]
#Output: 3
#Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
node = TreeNode(1)
node.left = TreeNode(2)
node.right = TreeNode(3)
node.left.left = TreeNode(4)
node.left.right = TreeNode(5)
s = bfs(node)
print("s=" + s)
diam = diameter_of_binary_tree(node)
print("diameter: " + str(diam))


root = [1,2]
#Output: 1
node = TreeNode(1)
node.left = TreeNode(2)
s = bfs(node)
print("s=" + s)
diam = diameter_of_binary_tree(node)
print("diameter: " + str(diam))
