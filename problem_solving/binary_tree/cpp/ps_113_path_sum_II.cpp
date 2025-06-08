/*
https://leetcode.com/problems/path-sum-ii/description/
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


void path_sum(TreeNode* root, 
        int targetSum, 
        int current_sum, 
        std::vector<std::vector<int>>& result,
        std::vector<int>& current) {
    if(!root) {
        return;
    }
    current_sum += root->val;
    current.push_back(root->val);
    if(current_sum == targetSum && (root->left == nullptr && root->right == nullptr)) {
        result.push_back(current);
    } else {
        path_sum(root->left, targetSum, current_sum, result, current);
        path_sum(root->right, targetSum, current_sum, result, current);
    }
    current.pop_back();
}

std::vector<std::vector<int>> path_sum(TreeNode* root, int targetSum) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    path_sum(root, targetSum, 0, result, current);
    return result;
}

int main() {
    //#root = [5,4,8,11,null,13,4,7,2,null,null,5,1]
    //#targetSum = 22
    //#Output: true
    TreeNode* node_root = new TreeNode(5);
    node_root->left = new TreeNode(4);
    node_root->right = new TreeNode(8);
    node_root->left->left = new TreeNode(11);
    node_root->left->right = nullptr;
    node_root->left->left->left = new TreeNode(7);
    node_root->left->left->right = new TreeNode(2);
    
    node_root->right->left = new TreeNode(13);
    node_root->right->right = new TreeNode(4);
    node_root->right->right->left = new TreeNode(5);
    node_root->right->right->right = new TreeNode(1);
    int target = 22;
    auto result =path_sum(node_root, target);
    print_vector_of_vector(result);
    
    //#root = [1,2,3]
    //# targetSum = 5
    //#Output: false
    //#(1 --> 2): The sum is 3.
    //#(1 --> 3): The sum is 4.
    node_root = new TreeNode(1);
    node_root->left = new TreeNode(2);
    node_root->right = new TreeNode(3);
    target = 5;
    result =path_sum(node_root, target);
    std::cout << "next example " << target << std::endl;
    print_vector_of_vector(result);
    
    
    //#root = []
    //#targetSum = 0
    //#Output: false
    node_root = nullptr;
    target = 0;
    std::cout << "next example " << target << std::endl;
    result =path_sum(node_root, target);
    print_vector_of_vector(result);
}
