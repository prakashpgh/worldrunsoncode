/*
https://leetcode.com/problems/same-tree
*/




#include "../../common_header.h"
#include "../../utils/utils.h"

using namespace std;


bool is_same_tree(TreeNode* p, TreeNode* q) {
    if(!p && !q) {
        return true;
    }
    if(!p || !q) {
        return false;
    }
    if(p->val != q->val) {
        return false;
    }
    return is_same_tree(p->left, q->left) && 
            is_same_tree(p->right, q->right);
}



int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = is_same_tree(p, q);
    std::cout << "result: " << result << std::endl;


    //case II
    p = new TreeNode(1);
    p->left = new TreeNode(2);

    q = new TreeNode(1);
    q->right = new TreeNode(2);

    result = is_same_tree(p, q);
    std::cout << "result: " << result << std::endl;

    //case III
    p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);

    q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);

    result = is_same_tree(p, q);
    std::cout << "result: " << result << std::endl;

    return 0;
}