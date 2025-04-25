/*
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/

#include<vector>
#include<iostream>
#include<functional>

class TrieNode {
    public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

    void insert(TrieNode* root, int num) {
        auto current = root;
        for(int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if(current->children[bit] == nullptr) {
                current->children[bit] = new TrieNode();
            }
            current = current->children[bit];
        }
    }

    int findMaxXor(TrieNode* root, int num) {
        auto current = root;
        int max_xor = 0;
        //std::cout << "find max" << std::endl;
        for(int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int toggle_bit = bit ^ 1;
            //std::cout << "fm start: " << i << "=>" << bit << std::endl;
            if(current) {
                if( current->children[toggle_bit] != nullptr) {
                    max_xor |= (1 << i);
                    current = current->children[toggle_bit];
                } else {
                    current = current->children[bit];
                }
            }
            //std::cout << "fm: " << i << "=>" << bit << std::endl;
        }
        //std::cout << "find max-3" << std::endl;
        return max_xor;
    }



    int find_maximum_xor(const std::vector<int>& nums)  {
        TrieNode* root = new TrieNode();
        for(int num : nums) {
            insert( root, num);
        }
        std::cout << "one.";
        int max_xor = 0;
        for(int num : nums) {
            max_xor = std::max( max_xor, findMaxXor(root, num));
        }

        std::function<void(TrieNode*)> delete_trie = [&] (TrieNode* node) {
            if(!node) {
                return;
            }
            delete_trie(node->children[0]);
            delete_trie(node->children[1]);
        };

        delete_trie(root);

        return max_xor;
    }



    int main() {
        std::vector<int> nums = {3,10,5,25,2,8};
        //Output: 28
        int result = find_maximum_xor(nums);
        std::cout << "result: " << result <<std::endl;


        nums = {14,70,53,83,49,91,36,80,92,51,66,70};
        result = find_maximum_xor(nums);
        std::cout << "result: " << result <<std::endl;
        //Output: 127

        return 0;
    }