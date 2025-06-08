/*'''
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
'''*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


TreeNode* delete_node_bst( TreeNode* root, int key) {
    if(!root) {
        return nullptr;
    }
    if(key > root->val) {
        root->right = delete_node_bst(root->right, key);
    } else if(key < root->val) {
        root->left = delete_node_bst(root->left, key);
    } else {
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
            return root;
        }
        if(root->left == nullptr) {
            auto right = root->right;
            delete root;
            root = nullptr;
            return right;
        } else if(root->right == nullptr) {
            auto left = root->left;
            delete root;
            root = nullptr;
            return left;
        } else {
            auto node = root->right;
            while(node->left != nullptr) {
                //this is the minimum
                node = node->left;
            }
            //replace...
            root->val = node->val;
            root->right = delete_node_bst(root->right, node->val);
        }
    }
    return root;
}

    


int main() {
    TreeNode* node_root = new TreeNode(5);
    node_root->left = new TreeNode(3);
    node_root->right = new TreeNode(6);
    node_root->left->left = new TreeNode(2);
    node_root->left->right = new TreeNode(4);
    node_root->right->left = nullptr;
    node_root->right->right = new TreeNode(7);
    auto result = delete_node_bst(node_root, 3);
    printBinaryTree(node_root);
    
    return 0;
}