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

/////////////////////

// Helper function to get the height of the tree
int hei(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + std::max(hei(root->left), hei(root->right));
}

/*
// Helper function to print nodes at a specific level
void printLevel(TreeNode* root, int level, std::vector<std::string>& lines, int start, int end) {
    if (!root) {
        return;
    }
    if (level == 1) {
        int mid = start + (end - start) / 2;
        lines.back()[mid] = std::to_string(root->val)[0]; // Handle multi-digit numbers carefully if needed
    } else if (level > 1) {
        int mid = start + (end - start) / 2;
        int left_end = mid - 1;
        int right_start = mid + 1;
        printLevel(root->left, level - 1, lines, start, left_end);
        printLevel(root->right, level - 1, lines, right_start, end);

        if (root->left) {
            int left_mid = start + (left_end - start) / 2;
            int current_mid = start + (end - start) / 2;
            int dist = current_mid - left_mid -1;
            if (lines.size() > lines.size() - level + 1) {
                lines[lines.size() - level + 1][left_mid + 1] = '/';
            }
        }
        if (root->right) {
            int right_mid = right_start + (end - right_start) / 2;
            int current_mid = start + (end - start) / 2;
            if (lines.size() > lines.size() - level + 1) {
                lines[lines.size() - level + 1][right_mid - 1] = '\\';
            }
        }
    }
}

// Function to print the binary tree in a structured format
void printBinaryTree(TreeNode* root) {
    int h = height(root);
    if (h == 0) return;
    int width = (1 << h) - 1; // Approximate width

    std::vector<std::string> lines(h);
    for (int i = 0; i < h; ++i) {
        lines[i] = std::string(width, ' ');
    }

    printLevel(root, 1, lines, 0, width - 1);
    for (int i = 2; i <= h; ++i) {
        printLevel(root, i, lines, 0, width - 1);
    }

    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }
}
    */