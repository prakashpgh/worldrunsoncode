/*
https://leetcode.com/problems/maximal-square/

https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

idea:
    

    recursive => from [0][0] to m-1,n-1
        if == 0, return zero
        
        a square is formed when right,diag and the down are 1s
        min(right, diag, down)
            keep a record of the max
-------------------
    iterative => fill from the bottom right
        if cell = 0, the memo is zero.
        else min(right, down, diag)
            keep tab on the max..
*/

#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>

class Solution {
    public:
    int max_square = INT_MIN;
    int rows = 0;
    int cols = 0;
    std::vector<std::vector<int>> memo;
    
    /*
    int recur(const std::vector<std::vector<char>>& matrix, 
                std::vector<std::vector<int>>& memo,
                int r, int c) {
        int len = matrix.size();
        
        if(r < 0 || r >= rows || c < 0 || c >= cols) {
            return 0;
        }
        if(memo[r][c] != -1) {
            return memo[r][c];
        }
        //std::cout << r << ',' << c << std::endl;
        int right = recur(matrix, memo, r, c+1);
        int down = recur(matrix, memo, r+1, c);
        int diag = recur(matrix, memo, r+1, c+1);
        
        if(matrix[r][c]=='0') {
            memo[r][c]=0;
            return 0;
        }
        //std::cout << "=>" << max_square << std::endl;
        int sq = 1 + std::min({right, down, diag});
        max_square = std::max(max_square, sq);
        //std::cout << r << ',' << c << '=' << sq << "=>" << max_square << std::endl;
        memo[r][c] = sq;
        return sq;
    } 


    int maximal_square(const std::vector<std::vector<char>>& matrix) {
        rows = matrix.size();
        if(rows > 0) {
            cols = matrix[0].size();
        }
        std::vector<std::vector<int>> memo(rows, std::vector<int>(cols, -1));
        recur( matrix, memo, 0, 0);
        
        //std::cout << "max_square: " << max_square << std::endl;
        max_square = max(max_square, 0);
        return max_square*max_square;
    }
    */

    int solve(const std::vector<std::vector<char>>& matrix, int r, int c) {
        if(r < 0 || r >= rows || c < 0 || c >= cols) {
            return 0;
        }
        if(matrix[r][c] == '0') {
            memo[r][c]= 0;
            return 0;
        }
        if(memo[r][c] != -1) {
            return memo[r][c];
        }
        int right = solve(matrix, r,c+1);
        int down = solve(matrix, r+1,c);
        int diag = solve(matrix, r+1,c+1);
        int sq = 1 + std::min({right, down, diag});
        memo[r][c]= sq;
        return sq;
    }

    int maximal_square(const std::vector<std::vector<char>>& matrix) {
        rows = matrix.size();
        max_square = INT_MIN;
        if(rows > 0 ) {
            cols = matrix[0].size();
        
        }
        memo.clear();
        memo.resize(rows, std::vector<int>(cols, -1));//resize.

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                int sq = solve(matrix, i,j);
                max_square = std::max(max_square, sq);
            }
        }
        return max_square*max_square;
    }




};


int main() {
    std::vector<std::vector<char>> matrix = { 
                                        {'1','0','1','0','0'},
                                        {'1','0','1','1','1'},
                                        {'1','1','1','1','1'},
                                        {'1','0','0','1','0'}};
    Solution solution;
    int result = solution.maximal_square(matrix);
    std::cout << "result: " << result << std::endl;

    //max_square = INT_MIN;    
    Solution solution2;
    matrix = { 
                {'0','1'},
                {'1','0'},
            };
    
    result = solution2.maximal_square(matrix);
    std::cout << "result: " << result << std::endl;


    Solution solution3;
    matrix = { 
                {'0'}
            };
    
    result = solution3.maximal_square(matrix);
    std::cout << "result: " << result << std::endl;
    
    
    Solution solution4;
    matrix = { 
                {'0','1'}
            };
    
    result = solution3.maximal_square(matrix);
    std::cout << "result: " << result << std::endl; 

    return 0;
}