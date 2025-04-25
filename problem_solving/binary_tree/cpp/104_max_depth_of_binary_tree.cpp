/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"

using namespace std;


int max_depth(TreeNode* root) {
    if(!root) {
        return 0;
    }
    return 1 + max(max_depth(root->left), max_depth(root->right) );
}

#include<queue>
int max_depth_iterative(TreeNode* root) {
    if(!root) {
        return 0;
    }
    std::queue<std::pair<TreeNode*, int>> q;
    int max_depth = 0;
    q.push({root, 1});
    
    while(!q.empty()) {
        auto items = q.front();
        TreeNode* node = items.first;
        int depth = items.second;
        q.pop();
        max_depth = max(max_depth, depth);
        if(node->left) {
            q.push({node->left, depth+1});
        }
        if(node->right) {
            q.push({node->right, depth+1});
        }
    }
    return max_depth;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int result = max_depth(root);
    std::cout << "result:" << result << std::endl;
    result = max_depth_iterative(root);
    std::cout << "result-iterative:" << result << std::endl;

    root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2);
    result = max_depth(root);
    std::cout << "result:" << result << std::endl;
    result = max_depth_iterative(root);
    std::cout << "result-iterative:" << result << std::endl;
}