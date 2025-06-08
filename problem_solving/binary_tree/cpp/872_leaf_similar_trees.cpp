/*
https://leetcode.com/problems/leaf-similar-trees/

dfs.. and append the leaf nodes

t: O(n1 + n2)   => we visit each node atleast onc
s: O(n1 + n2) => recursion.. height + store the leaves (N/2 + 1) leaves
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


void leaf_nodes_f(TreeNode* node, std::vector<int>& leaf_nodes) {
    if(!node) {
        return;
    }
    if(node->left == nullptr && node->right==nullptr) {
        leaf_nodes.push_back(node->val);
        return;
    }
    leaf_nodes_f(node->left, leaf_nodes);
    leaf_nodes_f(node->right, leaf_nodes);
}

bool leaf_similar_trees(TreeNode* root1, TreeNode* root2) {
    bool similar = false;
    std::vector<int> left;
    std::vector<int> right;
    leaf_nodes_f(root1, left);
    leaf_nodes_f(root2, right);
    return left == right;
}


int main() {

}
