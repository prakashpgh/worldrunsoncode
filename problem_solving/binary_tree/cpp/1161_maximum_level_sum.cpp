/*'''
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

level order traversal... 
    find the sum of each level.. 
    compare with max.
'''*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<queue>

int max_level_sum(TreeNode* root) {
    int max_sum = INT_MIN;
    int max_level = -1;
    std::queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()) {
        int l = q.size();
        long long current_sum = 0;
        level++;
        for(int i = 0; i < l; ++i) {
            auto node = q.front();
            current_sum += node->val;
            q.pop();
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        if(current_sum > max_sum) {
            max_sum = current_sum;
            max_level = level;
        }
    }
    return max_level;
}

int main() {
    //#root = [1,7,0,7,-8,null, null]
    TreeNode* node_root = new TreeNode(1);
    node_root->left = new TreeNode(7);
    node_root->right = new TreeNode(0);
    node_root->left->left = new TreeNode(7);
    node_root->left->right = new TreeNode(-8);
    node_root->right->left = nullptr;
    node_root->right->right = nullptr;
    int m = max_level_sum(node_root);
    std::cout << "max: " << m << std::endl;

    return 0;
}