/*
https://leetcode.com/problems/path-sum-iii/

use of prefix sum...
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


class Solution1 {
    private:
    std::unordered_map<long long, int> prefix_sum;
    int count;

    public:
    void solve(TreeNode* root, int target, long long current_sum) {
        if(!root) {
            return;
        }
        current_sum += root->val;
        if(prefix_sum.find(current_sum-target) != prefix_sum.end()) {
            count += prefix_sum[current_sum-target] ;
        }
        prefix_sum[current_sum]++;

        //continue with this node.. sum
        solve(root->left, target, current_sum);
        solve(root->right, target, current_sum);
        //pop operation
        prefix_sum[current_sum]--;
    }
    
    
    int pathsum(TreeNode* root, int target ) {
        count = 0;
        prefix_sum.clear();
        prefix_sum[0] = 1;
        solve(root, target, 0);
        std::cout << "pathsum: " << count << std::endl;
        return count;
    }
    
};



int main() {
    //#root = [10,5,-3,3,2,null,11,null, null, null, 1]
    //#targetSum = 8
    //
    TreeNode* node_root = new TreeNode(10);
    node_root->left = new TreeNode(5);
    node_root->right = new TreeNode(-3);
    node_root->left->left = new TreeNode(3);
    node_root->left->right = new TreeNode(2);
    node_root->right->left = nullptr;
    node_root->right->right = new TreeNode(11);
    node_root->left->left->left = nullptr;
    node_root->left->left->right = nullptr;

    node_root->left->right->left = nullptr;
    node_root->left->right->right = new TreeNode(1);
    int target = 8;
    Solution1 solve;
    std::cout << "calling pathsum " << std::endl;
    int count = solve.pathsum(node_root, target);
    std::cout << "count: " << count << std::endl;


    node_root = new TreeNode(5);
    node_root->left = new TreeNode(4);
    node_root->right = new TreeNode(8);
    node_root->left->left = new TreeNode(11);
    node_root->left->right = nullptr;
    node_root->right->left = new TreeNode(13);
    node_root->right->right = new TreeNode(4);
    node_root->left->left->left = new TreeNode(7);
    node_root->left->left->right = new TreeNode(2);
    node_root->right->right->left = new TreeNode(5);
    node_root->right->right->right = new TreeNode(1);
    std::cout << "calling pathsum " << std::endl;
    count = solve.pathsum(node_root, target);
    std::cout << "count: " << count << std::endl;

}