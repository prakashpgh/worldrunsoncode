/*
https://leetcode.com/problems/binary-tree-right-side-view

idea:
    do a bfs using queue, and at each level, get the last element

#meta
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<queue>


std::vector<int> right_side_view(TreeNode* root) {
    std::queue<TreeNode*> q;
    if(!root) {
        return {};
    }
    q.push(root);
    std::vector<int> result;
    while(!q.empty())  {
        int l = q.size();
        int val = 0;
        for(int i = 0; i < l; ++i) {
            auto node = q.front();
            val = node->val;
            q.pop();

            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        result.push_back(val);
    }
    return result;
}


int main() {
    TreeNode* node_root = new TreeNode(1);
    node_root->left = new TreeNode(2);
    node_root->right = new TreeNode(3);
    node_root->left->left = nullptr;
    node_root->left->right = new TreeNode(5);
    node_root->right->left = nullptr;
    node_root->right->right = new TreeNode(4);
    auto result = right_side_view(node_root);
    print_vector(result);
    return 0;
}
