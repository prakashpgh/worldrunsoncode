/*
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
1372_longest_zigzag_path_in_binary_tree.py

#tricky problem..
need to track, the direction of the previous step,number of steps

case 1) the previous direction was to right, 
            left, step+1
            right, 1  <= new stat
case 2) the previous direction was to left
            right, step+1
            left, 1  <= new stat
case 3) from the root
            left, "left", 1
            right, "right", 1

            >> why we need a new start => ABE... ends..  EHI is new start
    A
   / \
  B   C
 / \ / \
D  E F  G
   \
    H
   /
  I

*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>

class Solution {
    public:
int longest_path = 0;

void zigzag(TreeNode* root, bool right, int steps) {
    if(!root) {
        return;
    }
    longest_path = std::max(longest_path, steps);
    std::cout << root->val << "-->" << longest_path << "-->" << steps << std::endl;
    if(right) {
        zigzag(root->left, false, 1+steps);

        zigzag(root->right, true, 1);
    } else {
        zigzag(root->right, true, 1+steps);

        zigzag(root->left, false, 1);
    }
}


int longest_zigzag_path_in_binary_tree(TreeNode* root)  {
    if(!root) {
        return 0;
    }
    longest_path = 0;
    zigzag( root->right, true, 1);
    zigzag( root->left, false, 1);
    return longest_path;

}
};

int main() {
    TreeNode* node_root = new TreeNode(1);
    node_root->right = new TreeNode(2);
    
    node_root->right->left = new TreeNode(3);
    node_root->right->right = new TreeNode(4);
    
    node_root->right->right->left = new TreeNode(5);
    node_root->right->right->right = new TreeNode(6);
    
    node_root->right->right->left->right = new TreeNode(7);
    node_root->right->right->left->right->right = new TreeNode(8);
    
    Solution solve;
    auto result = solve.longest_zigzag_path_in_binary_tree(node_root);
    std::cout << "zigzag: " << result << std::endl;
}