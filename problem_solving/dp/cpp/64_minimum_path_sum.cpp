/*
https://leetcode.com/problems/minimum-path-sum/
*/

#include<vector>
#include<iostream>


//start with 0,0
//we need dp for only one row..
int minimum_path_sum_iterative(const std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    std::vector<int> dp(m);
    //calculate the dp for 1st row
    dp[0] = grid[0][0];
    for(int j = 1; j < n; ++j) {
        dp[j] = dp[j-1] + grid[0][j];
    }

    //calculate the remaining rows
    for(int i=1; i<m; ++i) {
        //first column of each row... will be traversed from the cell above it.
        dp[0] = dp[0] + grid[i][0];
        for(int j=1; j<n; ++j) {
            dp[j] = grid[i][j] + std::min(dp[j-1], dp[j]);
        }
    }
    return dp[n-1];
}

#include<map>
class Solution{
    public:
    std::map<std::pair<int, int>, int> memo;
    int rows = 0;
    int cols = 0;
    int recur(const std::vector<std::vector<int>>& grid, int r, int c) {
        if(r < 0 || r >= rows || c < 0 || c >= cols) {
            return INT_MAX;
        }
        if(r==0 && c==0) {
            memo[{r,c}] = grid[0][0];
            return grid[0][0];
        }
        if(memo.count({r,c}) > 0)  {
            return memo[{r,c}];
        }
        int up = recur(grid, r-1, c);
        int left = recur(grid, r, c-1);

        int min_path = std::min(up, left) + grid[r][c];
        memo[{r,c}] = min_path;
        return min_path;
    }


    int minimum_path_sum_recursive(const std::vector<std::vector<int>>& grid) {
        rows = grid.size();
        if(rows > 0) {
            cols = grid[0].size();
        }
        int min_path = recur(grid, rows-1, cols-1);
        return min_path;
    }
};

int main() {
    std::vector<std::vector<int>>grid = {{1,3,1},{1,5,1},{4,2,1}};
    //Output: 7
    int result = minimum_path_sum_iterative(grid);
    std::cout << "result-iterative: " << result << std::endl;

    Solution solve;
    result = solve.minimum_path_sum_recursive(grid);
    std::cout << "result-recursive: " << result << std::endl;


    grid = {{1,2,3},{4,5,6}};
    //Output: 12
    result = minimum_path_sum_iterative(grid);
    std::cout << "result-iterative: " << result << std::endl;

    Solution solve2;
    result = solve2.minimum_path_sum_recursive(grid);
    std::cout << "result-recursive: " << result << std::endl;
    return 0;
}


