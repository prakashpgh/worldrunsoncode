'''
450_delete_node_bst.py

3 cases:
value > root.val
    recurse in the right
value < root.val
    recurse in the left
value == root.val
    we actually do the delete here
        if not left
        if not right
        if both, find the successor.
            root.val = successor.
            delete the successor from right.
'''

from tree_node import TreeNode

def delete_node_bst(root: TreeNode, key: int) -> TreeNode:
    if not root:
        return root

    if key > root.val:
        root.right = delete_node_bst(root.right, key)
    elif key < root.val:
        root.left = delete_node_bst(root.left, key)    
    else:
        #equal case
        if not root.left:
            return root.right
        elif not root.right:
            return root.left
        else:
            #find the successor
            successor = root.right
            while successor.left:
                successor = successor.left
            root.val = successor.val
            #delete the succcessor
            root.right = delete_node_bst(root.right, successor.val)
    return root

    


