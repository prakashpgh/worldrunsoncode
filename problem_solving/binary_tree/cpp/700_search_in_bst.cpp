/*'''
https://leetcode.com/problems/search-in-a-binary-search-tree/

t: O(log N) ... best case, worst case N

s: O(H)
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;

TreeNode* search_bst_recursive(TreeNode* root, int val) {
    if(!root) {
        return nullptr;
    }
    if (root->val == val) {
        return root;
    } else if (val < root->val) {
        return search_bst_recursive(root->left, val);
    } else {
        return search_bst_recursive(root->right, val);
    }
    return nullptr;
}


TreeNode* search_bst_iterative(TreeNode* root, int val) {
    TreeNode* node = root;
    while(node) {
        if(node->val == val) {
            return node;
        } else if(val > node->val) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return nullptr;
}



int main() {

}