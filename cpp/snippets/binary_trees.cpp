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
        result.push_back(node->value);
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

bool is_balanced(TreeNode* root) {
    if(!root) {
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1) {
        return false;
    }
    return is_balanced(root->left) && is_balanced(root->right);
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