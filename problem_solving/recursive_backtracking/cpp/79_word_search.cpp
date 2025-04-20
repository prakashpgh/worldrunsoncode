/*
https://leetcode.com/problems/word-search/description/

time: O( r * c * 4**L)
space: O(L)
*/
#include<vector>
#include<string>
#include<tuple>
#include<iostream>

class Solution {
    std::string word;
    std::vector<std::vector<char>> board;
    int rows;
    int cols;
    std::vector<std::tuple<int, int>> neighbors = {{0, -1},{-1, 0},{0, 1},{1, 0}};
    int word_length;

    bool is_valid(int r, int c) {
        if(r >= 0 && r < rows && c >= 0 && c < cols) {
            return true;
        }
        return false;
    }

    bool recur(int r, int c, int index) {
        if(board[r][c] != word[index]) {
            return false;
        }
        if(index == word.length() - 1 ) {
            std::cout << "returning true..." << std::endl;
            return true;
        }
        char ch = board[r][c];
        board[r][c] = '#';
        for(const auto& tup : neighbors) {
            int x = r + std::get<0>(tup);
            int y = c + std::get<1>(tup);
            if(is_valid(x, y) && board[x][y] != '#') {
                auto ret = recur(x, y, index + 1);
                if(ret) {
                    return ret;
                }

            }
        }
        board[r][c] = ch;
        return false;
    }

public:
    bool word_search(const std::vector<std::vector<char>>& board, const std::string& word) {
        this->board = board;
        this->word = word;
        rows = board.size();
        this->word_length = word.length();
        if(rows > 0) {
            cols = board[0].size();
        }
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                auto ret = (board[i][j] == word[0]) && recur(i, j, 0);        
                if(ret) {
                    return ret;
                }
            }
        }
        return false;
    }


};


int main() {
    std::vector<std::vector<char>> board = {
                                        {'A','B','C','E'},
                                        {'S','F','C','S'},
                                        {'A','D','E','E'}
                                    };
    std::string word = "ABCCED";
    //Output: true
    Solution solv;
    auto result = solv.word_search(board, word);
    std::cout << "result: " << result << std::endl;

    ///
    board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    word = "SEE";
    //Output: true
    result = solv.word_search(board, word);
    std::cout << "result: " << result << std::endl;

    ///
    board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    word = "ABCB";
    result = solv.word_search(board, word);
    std::cout << "result: " << result << std::endl;
    //Output: false
}