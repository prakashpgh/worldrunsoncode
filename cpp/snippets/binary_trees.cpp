#include "../common_header.h"
#include<iostream>
#include<vector>
#include "../utils/utils.h"
#include<algorithm>

/*
          1
    2            3
4       5   6           7
*/
TreeNode* create_binary_tree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    return root;
}

TreeNode* tree(const std::vector<int>& vec, int start, int end) {
    int m = start + (end - start) / 2;
    TreeNode* node = new TreeNode(vec[m]);
    node->left = tree(vec, start, m-1);
    node->right = tree(vec, m+1, end);
    return node;
}

/*
create bst from an array
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/
TreeNode* array_to_binary_search_tree(const std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
    TreeNode* node = tree(vec, 0, vec.size()-1);
    return node;
}

/*
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
*/
TreeNode* list_to_binary_search_tree(ListNode* root) {
    TreeNode* root = nullptr;
    return root;
}

#include<queue>
std::vector<int> bfs(TreeNode* root) {
    std::vector<int> result;
    if(!root) {
        return result;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        auto node = q.front();
        result.push_back(node->val);
        q.pop();
        if(node->left) {
            q.push(node->left);
        }
        if(node->right) {
            q.push(node->right);
        }
    }
    return result;        
}

void inorder(TreeNode* root, std::vector<int>& results) {
    if(!root) {
        return;
    }
    inorder(root->left, results);
    results.push_back(root->value);
    inorder(root->right, results);
}

void preorder(TreeNode* root, std::vector<int>& results) {
    if(!root) {
        return;
    }
    results.push_back(root->value);
    preorder(root->left, results);
    preorder(root->right, results);    
}


void postorder(TreeNode* root, std::vector<int>& results) {
    if(!root) {
        return;
    }
    postorder(root->left, results);
    postorder(root->right, results);    
    results.push_back(root->value);
}

#include<stack>
/*  start with the current, dont fill the stack first.
    go to leftmost & keep putting in the stack.... 
    pop the left most.
    make current as the right of the left.
*/
void inorder_iterative(TreeNode* root, std::vector<int>& results) {
    if(!root) {
        return;
    }
    std::stack<TreeNode*> st;
    auto current = root;
    while(current || !st.empty()) {
        while(current) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        results.push_back(current->value);
        st.pop();
        current = current->right;
    }
}

/*  
root => left => right
put in stack...
iterate till stack is empty.
    pop from stack.
    put right,left 
*/
void preorder_iterative(TreeNode* root, std::vector<int>& results) {
    if(!root) {
        return;
    }
    std::stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        auto node = st.top();
        results.push_back(node->value);
        st.pop();
        if(node->right) {
            st.push(node->right);
        }
        if(node->left) {
            st.push(node->left);
        }
    }
}

/*
    put the root in to stack
    while stack {
        root value
        left
        right
    }
    reverse
*/
void postorder_iterative(TreeNode* root, std::vector<int>& results) {
    std::stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        auto node = st.top();
        results.push_back(node->value);
        st.pop();
        if(node->left) {
            st.push(node->left);
        }
        if(node->right) {
            st.push(node->right);
        }
    }
    std::reverse(results.begin(), results.end());
}

int height(TreeNode* root) {
    int h = 0;
    if(!root) {
        return 0;
    }
    h = 1 + std::max(height(root->left), height(root->right));
    return h;
}


bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

int checkHeight(TreeNode* node) {
        if (!node) return 0; // Base case: empty tree has height 0
        
        // Check left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Left subtree is unbalanced
        
        // Check right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Right subtree is unbalanced
        
        // Check if current node is balanced
        if (std::abs(leftHeight - rightHeight) > 1) return -1;
        
        // Return height of current node
        return std::max(leftHeight, rightHeight) + 1;
    }


int find_max(TreeNode* root) {
    if(!root) {
        return INT_MIN;
    }
    int maximum = root->value;
    int l = find_max(root->left);
    int r = find_max(root->right);
    maximum = std::max(maximum, l);
    maximum = std::max(maximum, r);
    return maximum;
}


int main() {
    TreeNode* root = create_binary_tree();
    std::cout << "bfs" << std::endl;
    auto results = bfs(root);
    print_vector(results);
    //printBinaryTree(root);
    return 0;

    std::cout << "inorder" << std::endl;
    results.clear();
    inorder(root, results);
    print_vector(results);

    std::cout << "preorder" << std::endl;
    results.clear();
    preorder(root, results);
    print_vector(results);

    std::cout << "post-order" << std::endl;
    results.clear();
    postorder(root, results);
    print_vector(results);
    results.clear();

    std::cout << "height" << std::endl;
    int h = height(root);
    std::cout << h << std::endl;

    std::cout << "is_balanced" << std::endl;
    bool bal = is_balanced(root);
    std::cout << bal << std::endl;

    std::cout << "find_maximum" << std::endl;
    int max = find_max(root);
    std::cout << max << std::endl;

    //iterative traversal
    std::cout << "inorder_iterative" << std::endl;
    inorder_iterative(root, results);
    print_vector(results);  
    results.clear(); 

    std::cout << "preorder_iterative" << std::endl;
    preorder_iterative(root, results);
    print_vector(results);   
    results.clear(); 
    
    std::cout << "postorder_iterative" << std::endl;
    postorder_iterative(root, results);
    print_vector(results);   

    
}