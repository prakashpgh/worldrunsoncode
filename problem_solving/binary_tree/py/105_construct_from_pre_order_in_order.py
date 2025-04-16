'''
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

binary tree from pre-orde and in order.
    in in-order, the left tree is left of the root, the right tree is right of the root.
    pre-order has the roots... 

    create a hashmap of the in-order: value,index   to find the index of the next root.
    maintain the current element index 

    preorder => get the next node...  from the pre-order
                create the TreeNode, 
                get its index from the map, recur the function..


'''
from tree_node import TreeNode
from tree_node import bfs


def construct_from_pre_order_in_order(inorder, preorder):

    #create a map of the value-index from preorder
    mp = {value:idx for idx, value in enumerate(inorder)}
    preorder_index = [0]

    def build_tree_recur(mp, preorder, left, right):
        if left > right:
            return None
        #get the root value    
        root_val = preorder[preorder_index[0]]
        #increment preorder index
        preorder_index[0] += 1
        #create the root node
        root = TreeNode(root_val)
        index = mp[root_val]
        #left
        root.left = build_tree_recur(mp, preorder, left, index-1)
        #right
        root.right = build_tree_recur(mp, preorder, index+1, right)
        return root
    return build_tree_recur(mp, preorder, 0, len(preorder)-1)




inorder = [3, 1, 4, 0, 5, 2]
preorder = [0, 1, 3, 4, 2, 5]
#Output: [0, 1, 2, 3, 4, 5]
root = construct_from_pre_order_in_order(inorder, preorder)
print("result: " + str(root))

