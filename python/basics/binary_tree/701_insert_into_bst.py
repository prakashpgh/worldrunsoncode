'''
https://leetcode.com/problems/insert-into-a-binary-search-tree/
'''
from tree_node import TreeNode

def insert_into_bst(bst: TreeNode, data: int):
    node = bst
    while node:
        if data > node.val:
            if node.right:
                node = node.right
            else:
                node.right = TreeNode(data)
                return bst
        else:
            if node.left:
                node = node.left
            else:
                node.left = TreeNode(data)
                return bst
    return TreeNode(data)


    
root = [4,2,7,1,3], val = 5
#Output: [4,2,7,1,3,5]
#result = insert_into_bst(root, val)

root = [40,20,60,10,30,50,70], val = 25
#Output: [40,20,60,10,30,50,70,null,null,25]


root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
#Output: [4,2,7,1,3,5]
