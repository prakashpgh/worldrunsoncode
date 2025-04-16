/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Idea:
    inorder => create a hashmap of the values to indexes
    
    pre order has nodes in order.
        use this to get the root nodes...
        create the Node..
        increment the preorder-index.
        get the index of this root node from the inorder-hashmap
        LEFT of this is the left node, IGHT of this is the left node
        first create the left node, and then the right node
*/


#include<queue>
#include<iostream>
#include<unordered_map>
#include "../../common_header.h"
#include "../../utils/utils.h"

std::unordered_map<int, int> inorder_value_index_map;
int pre_order_index=0;


TreeNode* create(int l, int r, const std::vector<int>& preorder) {
    if(l > r) {
        return nullptr;
    }
    int root_val = preorder[pre_order_index];
    pre_order_index += 1;
    
    int inorder_index = inorder_value_index_map[root_val];
    TreeNode* root = new TreeNode(root_val);
    
    root->left = create(l, inorder_index-1,preorder);
    root->right = create(inorder_index+1, r, preorder);
    return root;
}


TreeNode* construct_BT_inorder_postorder(const std::vector<int>& inorder, const std::vector<int>& preorder) {
    for(int i = 0; i < inorder.size(); ++i) {
        inorder_value_index_map[inorder[i]] = i;
    }
    int n = inorder.size();
    pre_order_index=0;
    auto root = create(0, n-1, preorder);
    
    std::vector<int> result;
    print_tree_inorder(root, result);
    print_vector(result);
    return root;
}


int main() {
    std::vector<int> inorder = {9,3,15,20,7};
    std::vector<int> preorder = {3,9,20,15,7};


    //Output: [3,9,20,null,null,15,7]
    TreeNode* root = construct_BT_inorder_postorder(inorder, preorder);
     return 0;
}