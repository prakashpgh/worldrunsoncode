/*
https://leetcode.com/problems/binary-tree-right-side-view/

level order traversal... take the last element of each level
*/

#include<queue>
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


std::vector<int> right_side_view(TreeNode* root) {
    if(!root) {
        return {};
    }
    std::queue<TreeNode*> q;
    q.push(root);
    std::vector<int> result;
    while(!q.empty())  {
        int len = q.size();
        for(int i = 0; i < len; ++i) {
            auto node = q.front();
            if(i == len-1) {
                result.push_back(node->val);
            }
            q.pop();            
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
    }
    return result;
}


int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = nullptr;
    p->left->right = new TreeNode(5);
    p->right->left = nullptr;
    p->right->right = new TreeNode(4);

    //std::vector<int> result1;
    //print_tree_inorder(p, result1);
    //print_vector(result1);
    //return 0;

    auto result = right_side_view(p);
    print_vector(result);
    
    //case II
    p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->left->left = new TreeNode(5);
    p->left->right = nullptr;
    p->right->left = nullptr;
    result = right_side_view(p);
    print_vector(result);

    p = new TreeNode(1);
    p->left = nullptr;
    p->right = new TreeNode(3);
    result = right_side_view(p);
    print_vector(result);

    p = nullptr;
    result = right_side_view(p);
    print_vector(result);

}