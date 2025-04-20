/*
https://leetcode.com/problems/word-search-ii/
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"

#include<iostream>
#include<vector>


using namespace std;

class TrieNode {
    public:
    std::string word;
    std::unordered_map<char, TrieNode*> children;

    TrieNode() {
    }
};  


class Trie {
    public:
    TrieNode* root;
    
    public:
    Trie() : root(new TrieNode()) {
    }

    void add_word(const std::string& word) {
        TrieNode* current = root;
        for(char ch : word) {
            if(current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        if(current) {
            current->word = word;
        }
    }

    bool search(const std::string& word) {
        TrieNode* current = root;
        for(char ch : word) {
            if(current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return (current != nullptr && current->word == word);
    }
};


class Solution
{
private:
    int rows;
    int cols;

    void recur(std::vector<std::vector<char>>& board, int r, int c, TrieNode* current, std::vector<string>& results) {
        if( !is_valid(r, c)) {
            //std::cout << "return-1: " << r << "," << c << std::endl;
            return;
        }
        char ch = board[r][c];
        if(board[r][c]== '#') {
            //std::cout << "return-2: " << ch << std::endl;
            return;
        }
        
        //std::cout << "before-1: " << ch << std::endl;
        if( current->children.find(ch) == current->children.end() ) {
            //std::cout << "return-3: " << ch << std::endl;
            return;
        }
        //std::cout << "after-1" << std::endl;
        current = current->children[ch];
        if( !current->word.empty() ) {
            //std::cout << "word found" << std::endl;
            results.push_back(current->word);
            current->word = "";
        }       
        
        ch = board[r][c];
        board[r][c] = '#';

        for(const auto& tup : neighbors) {
            int row = r + std::get<0>(tup);
            int col = c + std::get<1>(tup);
            recur(board, row, col, current, results);
        }

        board[r][c] = ch;
    }

    std::vector<std::tuple<int, int>> neighbors = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    bool is_valid(int r, int c) {
        if(r < 0 || r >= rows || c < 0 || c >= cols ) {
            return false;
        }
        return true;
    }
public:

std::vector<string> findWords(std::vector<std::vector<char>>& board, const std::vector<std::string>& words)  {
    Trie trie;
    for(const auto& word : words) {
        trie.add_word(word);
    }
    //std::cout << trie.search("oath") << std::endl;
    rows = board.size();
    cols = 0;
    if(rows > 0) {
        cols = board[0].size();
    }
    std::vector<std::string> result;
    for(int r=0; r < rows; ++r) {
        for(int c=0; c<cols; ++c) {
            recur(board, r, c, trie.root, result);
        }
    }
    return result;
}
};

int main() {
    /*
    Trie trie;
    trie.add_word("apple");
    trie.add_word("mango");
    std::string ss = "apple";
    std::cout << trie.search(ss) << std::endl;
    std::cout << trie.search("app") << std::endl;
    std::cout << trie.search("apple1") << std::endl;
    std::cout << trie.search("mango") << std::endl;
    */
    std::vector<std::vector<char>> board = {
                                            {'o','a','a','n'},
                                            {'e','t','a','e'},
                                            {'i','h','k','r'},
                                            {'i','f','l','v'}};
    std::vector<std::string> words = {"oath","pea","eat","rain"};
    //Output: {'eat','oath'}
    Solution solv;
    auto result = solv.findWords( board, words);    
    print_vector(result);    
    

    board = {{'a','b'},{'c','d'}};
    words = {"abcb"};
    //Output: {}
    Solution solv2;
    result = solv2.findWords( board, words);    
    print_vector(result);
}