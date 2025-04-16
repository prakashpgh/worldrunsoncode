/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

in inorder BST, the nodes are stored in ascending order.
*/

#include<stack>
#include<iostream>
#include "../../common_header.h"
#include "../../utils/utils.h"



int kth_smallest(TreeNode* root, int k)  {
    auto current = root;
    std::stack<TreeNode*> st;
    int count = 0;
    while (!st.empty() or current) {
        while(current) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();
        count += 1;
        if(count == k) {
            return current->val;
        }
        current = current->right;
    }
    return -1;
}



int main() {
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(1);
    p->right = new TreeNode(4);
    p->left->left = nullptr;
    p->left->right = new TreeNode(2);
    int k=1;
    auto result = kth_smallest(p, k);

    p = new TreeNode(5);
    p->left = new TreeNode(3);
    p->right = new TreeNode(6);
    p->left->left = new TreeNode(2);
    p->left->right = new TreeNode(4);
    p->left->left->left = new TreeNode(1);
    k=3;
    result = kth_smallest(p, k);    
    std::cout << "result:" << result << std::endl;
}