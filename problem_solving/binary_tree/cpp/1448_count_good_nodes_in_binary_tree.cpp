/*
#https://leetcode.com/problems/count-good-nodes-in-binary-tree/
bfs
    pass the max of the max( node_value, max_value ) to the nodes..
    check value and increment the count accordingly
    do a bfs... so you can put the node and the sum on the Q

MISTAKE understood the problem wrong initially
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


int count_good_nodes_in_binary_tree(TreeNode* root, int max_value) {
    if(!root) {
        return 0;
    }
    int count = 0;
    if(root->val >= max_value) {
        count++;
    }
    max_value = std::max(max_value, root->val);
    count += count_good_nodes_in_binary_tree(root->left, max_value);
    count += count_good_nodes_in_binary_tree(root->right, max_value);
    return count;
}

int count_good_nodes_in_binary_tree(TreeNode* root) {
    int count = count_good_nodes_in_binary_tree(root, INT_MIN);
    return count;
}


int main() {
    //#root = [3,1,4,3,None,1,5]
    //#Output: 4
    //#Explanation: Nodes in blue are good.
    TreeNode* node_root = new TreeNode(3);
    node_root->left = new TreeNode(1);
    node_root->right = new TreeNode(4);
    node_root->left->left = new TreeNode(3);
    node_root->left->right = nullptr;
    node_root->right->left = new TreeNode(1);
    node_root->right->right = new TreeNode(5);
    int count = count_good_nodes_in_binary_tree(node_root);
    std::cout << "count: "  << count << std::endl;
    
    
    
    //#root = [3,3,None,4,2]
    //#Output: 3
    //#Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
    node_root = new TreeNode(3);
    node_root->left = new TreeNode(3);
    node_root->right = nullptr;
    node_root->left->left = new TreeNode(4);
    node_root->left->right = new TreeNode(2);
    count = count_good_nodes_in_binary_tree(node_root);
    std::cout << "count: "  << count << std::endl;
    
    
    //#root = [1]
    //#Output: 1
    //#Explanation: Root is considered as good.
    node_root = new TreeNode(3);
    count = count_good_nodes_in_binary_tree(node_root);
    std::cout << "count: "  << count << std::endl;
    return 0;    
}
