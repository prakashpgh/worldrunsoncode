/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/

level order traversal using q.
*/

#include<queue>
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"

using namespace std;



std::vector<double> average_levels(TreeNode* root) {
    std::vector<double> avg;
    std::queue<TreeNode*> q;
    if(!root) {
        return {};
    }
    q.push(root);
    while(!q.empty()) {
        int len = q.size();
        double a = 0.0;
        for (int i = 0; i < len; ++i) {
            auto node = q.front();
            q.pop();
            a += node->val;
            
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        avg.push_back(a/len);
    }
    return avg;
}


int main() {
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->left->left = nullptr;
    p->left->right = nullptr;
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(7);
    auto result = average_levels(p);
    print_vector(result);

    //case II
    p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->left->left = new TreeNode(15);
    p->left->right = new TreeNode(7);
    result = average_levels(p);
    print_vector(result);
}