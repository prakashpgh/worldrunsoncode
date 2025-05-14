/*
https://leetcode.com/problems/unique-paths-ii/

Idea: 
Approach I:
    iterative.
    we can use std::vector<int> dp(cols, 0) => only 1 row..  
    Note we only need the dp array from the row above and the columns before the cell.
    dp[0] = 1
    and keep filling the dp array. where there is no obstacle.

idea:   
    2 choices - right or down.
    base cases: when reached bottom right, path = 1
        when 1, return zero, 
        when out of bounds return zero

    iterative:
        dp[i][j] => number of unique ways to reach that particular cell
        start from top left to bottom right.

        return dp[rows-1][cols-1]

*/
#include<vector>
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


int unique_paths_iterative(const std::vector<std::vector<int>>& grid) {
    int rows = grid.size();
    if(rows==0) {
        return 0;
    }
    int cols = grid[0].size();
    if(cols == 0) {
        return 0;
    }
    std::vector<int> dp(cols, 0);
    if(grid[0][0] == 0) {
        dp[0] = 1;
    }
    //fill row = 0
    for(int j=1; j < cols; ++j) {
        if(grid[0][j]==0) {
            dp[j] = dp[j-1];
        } else {
            dp[j] = 0;
        }
    }
    for(int i = 1; i < rows; ++i) {
        if(grid[i][0] == 0) {
            dp[0] = dp[0];
        } else {
            dp[0] = 0;
        }
        for(int j=1;j<cols;++j) {
            if(grid[i][j] == 0) {
                dp[j] += dp[j-1];
            } else {
                dp[j] = 0;
            }
        }
    }
    return dp[cols-1];
}


class Solution {
public:
    int rows;
    int cols;

    int recur(const std::vector<std::vector<int>>& grid, int r, int c) {
        if(r < 0 || r >= rows || c < 0 || c >= cols) {
            return 0;
        }
        if(grid[r][c] == 1) {
            return 0;
        }
        if(r==0 && c==0) {
            return 1;
        }
        int paths = recur(grid, r-1,c) + recur(grid, r, c-1);
        return paths;
    }

    int unique_paths_recursive(const std::vector<std::vector<int>>& grid) {
        rows = grid.size();
        if(rows == 0) {
            return 0;
        }
        cols = grid[0].size();
        int paths = recur(grid, rows-1, cols-1);
        return paths;    
    }

};

int main() {
    std::vector<std::vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    int result = unique_paths_iterative(grid);
    std::cout << "result-iterative: " << result << std::endl;
    //2
    Solution solv;
    result = solv.unique_paths_recursive(grid);
    std::cout << "result-recursive: " << result << std::endl;

    grid = {{0,1},{0,0}};
    result = unique_paths_iterative(grid);
    std::cout << "result-iterative: " << result << std::endl;
    //1
    Solution solv2;
    result = solv2.unique_paths_recursive(grid);
    std::cout << "result-recursive: " << result << std::endl;

    return 0;
}
