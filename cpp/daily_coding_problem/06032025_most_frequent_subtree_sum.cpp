/*
06032025_most_frequent_subtree_sum.cpp
Given the root of a binary tree, find the most frequent subtree sum. The subtree sum of a node is the sum of all values under a node, including the node itself.

For example, given the following tree:

  5
 / \
2  -5
Return 2 as it occurs twice: once as the left leaf, and once as the sum of 2 + 5 - 5
*/

#include "../common_header.h"
#include<iostream>
#include<vector>
#include "../utils/utils.h"
#include<algorithm>
#include<unordered_set>

std::unordered_map<int, int> sum_frequency;

int sum_tree(TreeNode* root) {
    if(!root) {
        return 0;
    }
    int sum = root->val + sum_tree(root->left) + sum_tree(root->right);
    sum_frequency[sum] += 1;
    return sum;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-5);

    sum_tree(root);
    int max = INT_MIN;
    for( const auto& pair : sum_frequency) {
        if(pair.second > max) {
            max = pair.second;
        }
    }
    std::cout << max << std::endl;
}