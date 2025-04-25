/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/?ref=gcse_outind
https://www.youtube.com/watch?v=vssbwPkarPQ
Idea:
    put the root on stack.
    while stack empty, 
        pop, 
        push right, 
        push left.
        peek.
        the right of current should point to the left node(peek)
        left of current should be None
'''
*/

#include<queue>
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<stack>

// Helper function to print the flattened tree (for testing)
void printFlattenedTree(TreeNode* root) {
    TreeNode* current = root;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->right;
    }
    std::cout << "nullptr" << std::endl;
}

void flatten_binary_tree_to_linkedlist(TreeNode* root) {
    if(!root) {
        return;
    }
    TreeNode* node = root;
    std::stack<TreeNode*> st;
    st.push(node);

    TreeNode* head = new TreeNode(-1);
    TreeNode* traverse = head;
    while(!st.empty()) {
        TreeNode* top_node = st.top();
        std::cout << top_node->val << std::endl;
        st.pop();

        if(top_node->right) {
            st.push(top_node->right);
        }
        if(top_node->left) {
            st.push(top_node->left);
        }
        traverse->right = top_node;
        traverse->left = nullptr;
        traverse = traverse->right;
    }
    root = head->right;
}



int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(5);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->left = nullptr;
    p->right->right = new TreeNode(6);
    flatten_binary_tree_to_linkedlist(p);

    printFlattenedTree(p);

    p = nullptr;
    flatten_binary_tree_to_linkedlist(p);
    printFlattenedTree(p);

    p = new TreeNode(0);
    flatten_binary_tree_to_linkedlist(p);
    printFlattenedTree(p);
    return 0;
}

