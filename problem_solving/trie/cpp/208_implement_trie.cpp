/*
*/

#include<string>
#include<unordered_map>
#include<iostream>

class TrieNode {
    public:
    std::unordered_map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode() : is_end_of_word(false) {
    }

};


class Trie {
    private:
    TrieNode* root;

    public:
    Trie() : root(new TrieNode()) {
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for(char c : word) {
            if(current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->is_end_of_word = true;
    }

    bool search(const std::string& word) {
        TrieNode* current = root;
        for(char c : word) {
            if(current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return current != nullptr && current->is_end_of_word;
    }

    bool startsWith(const std::string prefix) {
        TrieNode* current = root;
        for(char c : prefix) {
            if(current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return current != nullptr;
    }

};


int main() {
    Trie* trie = new Trie();
    
    trie->insert("apple");
    std::cout << trie->search("apple") << std::endl;   // return True
    std::cout << trie->search("app") << std::endl;     // return False
    std::cout << trie->startsWith("app") << std::endl; // return True
    trie->insert("app");
    std::cout << trie->search("app") << std::endl;     // return True
    return 0;
}