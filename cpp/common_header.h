#include<iostream>
#include<vector>

struct ListNode {
    ListNode(int value) : val(value), next(nullptr) {
    }
    ListNode* next;
    int val;
};

void print_linked_list(ListNode* node) {
    while (node) {
        std::cout << node->val << " => ";
        node = node->next;
    }
    std::cout << std::endl;
}

struct TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {
    }
};



void print_tree_inorder(TreeNode* root, std::vector<int>& result) {
    if(!root) {
        return;
    }
    print_tree_inorder(root->left, result);
    result.push_back(root->val);
    print_tree_inorder(root->right, result);
}