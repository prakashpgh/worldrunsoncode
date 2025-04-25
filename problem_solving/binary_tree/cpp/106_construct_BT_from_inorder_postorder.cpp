/*

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

*/


#include<queue>
#include<iostream>
#include<unordered_map>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"

std::unordered_map<int, int> inorder_value_index_map;
int post_order_index=-1;


TreeNode* create(int l, int r, const std::vector<int>& postorder) {
    if(l > r) {
        return nullptr;
    }
    std::cout << "two" << post_order_index << std::endl;
    print_vector(postorder);
    int root_val = postorder[post_order_index];
    print_vector(postorder);
    post_order_index -= 1;
    
    std::cout << "two-B" << std::endl;
    int inorder_index = inorder_value_index_map[root_val];
    TreeNode* root = new TreeNode(root_val);
    std::cout << root_val << std::endl;
    
    root->right = create(inorder_index+1, r, postorder);
    root->left = create(l, inorder_index-1,postorder);
    return root;
}


TreeNode* construct_BT_inorder_postorder(const std::vector<int>& inorder, const std::vector<int>& postorder) {
    for(int i = 0; i < inorder.size(); ++i) {
        inorder_value_index_map[inorder[i]] = i;
    }
    //std::cout << "one" << std::endl;
    int n = inorder.size();
    post_order_index=n-1;
    int r = postorder[post_order_index];
    //std::cout << r << std::endl;
    auto root = create(0, n-1, postorder);
    
    std::vector<int> result;
    print_tree_inorder(root, result);
    print_vector(result);
    return root;
}


int main() {
    std::vector<int> inorder = {9,3,15,20,7};
    std::vector<int> postorder = {9,15,7,20,3};


    //Output: [3,9,20,null,null,15,7]
    TreeNode* root = construct_BT_inorder_postorder(inorder, postorder);
     return 0;
}