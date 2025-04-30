'''
https://leetcode.com/problems/binary-tree-inorder-traversal/
'''

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>



class Solution1 {

    private:
    std::vector<int> results;
    void recur(TreeNode* root) {
        if(!root) {
            return;
        }
        recur(root->left);
        results.push_back(root->val);
        recur(root->right);
    }
     

    public:
    std::vector<int> inorder_traversal(TreeNode* root) {
        results.clear();
        recur(root);
        return results;
    }
};


std::vector<int> inorder_traversal_iterative(TreeNode* root)  {
    std::vector<int> results;
    TreeNode* current = root;
    std::stack<int> st;
    while(current || !results.empty()) {
        while(current) {
            st.push(current);
            current = current->left;
        }
        if(!st.empty()) {
            current = st.top();
            st.pop();
            results.push_back(current->value);
            if(current->right) {
                st.push(current->right);
            }
        }
    }
    return results;
}




def binary_tree_inorder_iterative(root: TreeNode):
    result = []
    current = root
    stack =[]
    while current or stack:
        #keep appending the left most in the stack
        while current:
            stack.append(current)
            current = current.left

            current = stack.pop()
            result.append(current.val)
            current = current.right

    return result



node_root = TreeNode(1)
node_root.left = None
node_root.right = TreeNode(2)
node_root.right.left = TreeNode(3)
result = binary_tree_inorder_traversal(node_root)
print("binary_tree_inorder_traversal: " + str(result))
