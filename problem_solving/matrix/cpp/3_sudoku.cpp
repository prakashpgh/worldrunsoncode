/*
https://leetcode.com/problems/valid-sudoku/
*/
#include<unordered_set>
#include<iostream>
//#include '../../utils/utils.h'
#include<vector>
using namespace std;

bool is_ValidSudoku(vector<vector<char>>& board) {
    int rows = board.size();
    int cols = board.size();
    std::cout << "one " << std::endl;
    for(int i = 0; i < rows; ++i) {
        std::unordered_set<int> contains;
        for(int j = 0; j < cols; ++j) {
            if (board[i][j] == '.') {
                continue;
            }
            int num = board[i][j] - '0';
            if (contains.find(num) != contains.end()) {
                return false;
            }
            contains.insert(num);
        }
    }
    std::cout << "2 " << std::endl;
    //columns
    for(int i = 0; i < cols; ++i) {
        std::unordered_set<int> contains;
        for(int j = 0; j < rows; ++j) {
            if (board[j][i] == '.') {
                continue;
            }
            int num = board[j][i] - '0';
            if (contains.find(num) != contains.end()) {
                return false;
            }
            contains.insert(num);
        }
    }

    //square.
    int dividor = 3;

    for(int r = 0; r < dividor*dividor; r=r+dividor) {
        for(int c = 0; c < dividor*dividor; c=c+dividor) {
                int startX=r;
                int startY=c;
                std::unordered_set<int> contains;
                std::cout << startX << "," << startY << std::endl;
                for(int i = startX; i < startX+dividor; ++i) {
                    for(int j = startY; j < startY+dividor; ++j) {
                        if (board[i][j] == '.') {
                            continue;
                        }
                        int num = board[i][j] - '0';
                        if (contains.find(num) != contains.end()) {
                            return false;
                        }
                        contains.insert(num);
                    }
                }

        }
    }
    return true;
}



int main() {
    vector<vector<char>> board = 
    {{'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
    //Output: true
    bool result = is_ValidSudoku(board);
    std::cout << "result: " << result << std::endl;

board = 
{{'8','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}};
//Output: false
    result = is_ValidSudoku(board);
    std::cout << "result: " << result << std::endl;

board = 
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    //true
    result = is_ValidSudoku(board);
    std::cout << "result: " << result << std::endl;

board = {
            {'.','.','.','.','5','.','.','1','.'},
            {'.','4','.','3','.','.','.','.','.'},
            {'.','.','.','.','.','3','.','.','1'},
            {'8','.','.','.','.','.','.','2','.'},
            {'.','.','2','.','7','.','.','.','.'},
            {'.','1','5','.','.','.','.','.','.'},
            {'.','.','.','.','.','2','.','.','.'},
            {'.','2','.','9','.','.','.','.','.'},
            {'.','.','4','.','.','.','.','.','.'}
        };
//false
    result = is_ValidSudoku(board);
    std::cout << "result: " << result << std::endl;

}