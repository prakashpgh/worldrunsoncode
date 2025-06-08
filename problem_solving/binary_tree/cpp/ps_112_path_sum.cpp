/*'''
https://leetcode.com/problems/path-sum/

keep traversing the tree... till you encounter the leaf node... and check the target-sum
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


bool path_sum(TreeNode* root, int targetSum, int current_sum) {
    bool result = false;
    if(!root) {
        if(current_sum==targetSum) {
            return true;
        }
        return false;
    }
    current_sum += root->val;
    if(current_sum == targetSum && (root->left==nullptr && root->right==nullptr)) {
        return true;    
    }
    bool left = path_sum(root->left, targetSum, current_sum);
    bool right = path_sum(root->right, targetSum, current_sum);

    return (left || right);
}


int main() {
    //#root = [5,4,8,11,null,13,4,7,2,null,null,null,1]
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
    node_root->right->right->right = new TreeNode(1);
    bool ret =path_sum(node_root, 22, 0);
    std::cout << "path_sum: " << ret << std::endl;
    
    //#root = [1,2,3]
    //# targetSum = 5
    //#Output: false
    //#(1 --> 2): The sum is 3.
    //#(1 --> 3): The sum is 4.
    node_root = new TreeNode(1);
    node_root->left = new TreeNode(2);
    node_root->right = new TreeNode(3);
    ret =path_sum(node_root, 5, 0);
    std::cout << "path_sum: " << ret << std::endl;
    
    
    //#root = []
    //#targetSum = 0
    //#Output: false
    node_root = nullptr;
    ret =path_sum(node_root, 0, 0);
    std::cout << "path_sum: " << ret << std::endl;
}
