/*
traverse tree by any method.
find the abs differences between the node and the children.
keep the min_diff
*/

#include<stack>
#include<iostream>
#include "../../common_header.h"
#include "../../utils/utils.h"


int minimum_absolute_diff_in_bst(TreeNode* root) {
    int min_diff = INT_MAX;
    std::stack<TreeNode*> st;    
    auto current = root;
    while(!st.empty() || current) {
        while(current) {
            st.push(current);
            current=current->left;
        }

        current = st.top();
        if(current->right) {
            min_diff = std::min(min_diff, std::abs(current->val - current->right->val));
        }
        if(current->left) {
            min_diff = std::min(min_diff, std::abs(current->val - current->left->val));
        }
        st.pop();
        current = current->right;
    }
    return min_diff;
}



int main() {
    TreeNode* p = new TreeNode(4);
    p->left = new TreeNode(2);
    p->right = new TreeNode(6);
    p->left->left = new TreeNode(6);
    p->left->right = new TreeNode(3);
    auto result = minimum_absolute_diff_in_bst(p);
    std::cout << "result: " << result << std::endl;

    p = new TreeNode(1);
    p->left = new TreeNode(0);
    p->right = new TreeNode(48);
    p->left->left = new TreeNode(12);
    p->left->right = new TreeNode(49);
    result = minimum_absolute_diff_in_bst(p);
    std::cout << "result: " << result << std::endl;
    return 0;
}