/*
https://leetcode.com/problems/inorder-successor-in-bst/ 
 */

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


TreeNode* inorder_successor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = nullptr;
    if(!root || !p) {
        return nullptr;
    }
    auto current = root;
    while (current) { 
        if(p->val >= current->val)  {
            current = current->right;
        } else {
            successor = current;
            current = current->left;
        }
    }
    return successor;
}


int main() {

    return 0;
}