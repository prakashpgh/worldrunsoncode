/*
https://leetcode.com/problems/inorder-successor-in-bst-ii/ 
 */

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


Node* inorder_successor(Node* p) {
    if(!p) {
        return nullptr;
    }
    auto current = p;
    // Case 1: Node has a right child
    // Successor is the leftmost node in the right subtree    
    if(current->right) {
        current = current->right;
        while(current->left) {
            current = current->left;
        }
        return current;
    }

    // Case 2: Node has no right child
    // Move up until we find a parent reached from its left child
    while(current->parent && current==current->parent->right) {
        current = current->parent;
    }
    return current->parent;

}

int main() {

    return 0;
}