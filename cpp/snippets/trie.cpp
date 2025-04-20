/*
TrieNode =>map<char, TrieNode*>

Trie
    TrieNode* root;

    Each character is a key in the dictionary.
*/

#include<string>
#include<iostream>
#include<unordered_map>


class TrieNode {
    public:
    std::unordered_map<char, TrieNode*> children;
    bool end_of_word;

    TrieNode() : end_of_word(false) {
    }
};

class Trie {
    private:
    TrieNode* root;

    public:
    Trie() : root(new TrieNode() ){

    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for(char c : word) {
            if(current->children.find(c) == current->children.end() ) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->end_of_word = true;
    }

    bool search(const std::string& word) {
        TrieNode* current = this->root;
        for (char c : word) {
            if(current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return current && current->end_of_word;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* current = this->root;
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
    Trie trie;
    trie.insert("apple");
    trie.insert("apricot");
    trie.insert("banana");

    std::cout << "Search 'apple': " << trie.search("apple") << std::endl;     // Output: 1
    std::cout << "Search 'app': " << trie.search("app") << std::endl;         // Output: 0
    std::cout << "StartsWith 'app': " << trie.startsWith("app") << std::endl; // Output: 1
    std::cout << "Search 'apricots': " << trie.search("apricots") << std::endl; // Output: 0


    return 0;
}
