'''
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Idea:
    inorder => create a hashmap of the values to indexes
    
    post order has nodes in reverse order.
        use this to get the root nodes...
        create the Node..
        increment the preorder-index.
        get the index of this root node from the inorder-hashmap
        create right node => note in the post order, need to create the right node first #mistake
        create left node
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def construct_binary_tree_from_inorder_postorder(inorder: list[int], postorder:list[int]):
    #create the map of values to index
    N=len(inorder)
    if len(inorder) != len(postorder):
        return None
    value_index_dict={ value:index for index, value in enumerate(inorder) }

    def construct_tree(l, r):
        #create the node from the index.A
        if r < l:
            return None
        val = postorder.pop()
        if val not in value_index_dict:
            return None

        root = TreeNode(val)
        index_in_order = value_index_dict[val]
        root.right = construct_tree(index_in_order+1, r)
        root.left = construct_tree(l, index_in_order-1)
        return root

    tree = construct_tree(0, N-1)
    return tree




inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
#Output: [3,9,20,null,null,15,7]
tree = construct_binary_tree_from_inorder_postorder(inorder, postorder)
print("tree: " + str(tree))
