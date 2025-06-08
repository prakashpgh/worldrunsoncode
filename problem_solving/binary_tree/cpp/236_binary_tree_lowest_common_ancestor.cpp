/*'''
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/

1) if root val === p or q, then root is the lca

1) search left root , right root.
    if both return then passed node => since each node is present in left and right nodes

    if both return valid nodes, then return the passed node.
    else if left,left, or rigt
    
    return the search when you find eithe p or q

#meta
'''*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>



TreeNode* lca(TreeNode* root, TreeNode* p , TreeNode* q) {
    if(!root) {
        return nullptr;
    }
    if(root->val == p->val || root->val == q->val) {
        return root;
    }
    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);
    if(left && right) {
        return root;
    }
    if(left) {
        return left;
    } else {
        return right;
    }
    return nullptr;
}


int main() {
    //root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    //Output: 3

    //root = {6,2,8,0,4,7,9,None,None,3,5};
    //p = 2;
    //q = 8;
    //#Output: 6
    TreeNode* node_root = new TreeNode(6);
    node_root->left = new TreeNode(2);
    TreeNode* p = node_root->left;
    node_root->right = new TreeNode(8);
    TreeNode* q = node_root->right;
    node_root->left->left = new TreeNode(0);
    node_root->left->right = new TreeNode(4);
    node_root->right->left = new TreeNode(7);
    node_root->right->right = new TreeNode(9);
    node_root->left->left->left = nullptr;
    node_root->left->left->right = nullptr;
    node_root->left->right->left = new TreeNode(3);
    node_root->left->right->right = new TreeNode(5);
    
    
    auto result = lca(node_root, p, q);
    std::cout << "lca: " << result->val << std::endl;
    
    //#root = [6,2,8,0,4,7,9,None,None,3,5]
    ///#p = 2
    //#q = 4
    //#Output: 2
    node_root = new TreeNode(6);
    node_root->left = new TreeNode(2);
    p = node_root->left;
    node_root->right = new TreeNode(8);
    
    node_root->left->left = new TreeNode(0);
    node_root->left->right = new TreeNode(4);
    q = node_root->left->right;
    node_root->right->left = new TreeNode(7);
    node_root->right->right = new TreeNode(9);
    node_root->left->left->left = nullptr;
    node_root->left->left->right = nullptr;
    node_root->left->right->left = new TreeNode(3);
    node_root->left->right->right = new TreeNode(5);
    
    result = lca(node_root, p, q);
    std::cout << "lca: " << result->val << std::endl;
    
    
    //#root = [2,1]
    //#p = 2
    //#q = 1
    //#Output: 2
    node_root = new TreeNode(2);
    p = node_root;
    node_root->left = new TreeNode(1);
    q = node_root->left;
    
    result = lca(node_root, p, q);
    std::cout << "lca: " << result->val << std::endl;
    
}
