/*
https://leetcode.com/problems/triangle/

//using optimized space
//moving from bottom of triangle to top..
*/

#include<vector>
#include<iostream>
#include<unordered_map>


int minimum_triangle(const std::vector<std::vector<int>>& triangle) {
    int rows = triangle.size();
    if(rows == 0) {
        return 0;
    }
    if(rows == 1) {
        return triangle[0][0];
    }
    std::vector<int> dp = triangle[rows-1];// last row..
    for(int i = rows-2; i >= 0; --i) {
        for(int j = 0; j < triangle[i].size(); ++j) {
            dp[j] = triangle[i][j] + std::min(dp[j], dp[j+1]);
        }
    }
    return dp[0];
} 


#include<map>

std::map<std::pair<int, int>, int> memo;
int minimum_triangle_recursive(const std::vector<std::vector<int>>& triangle, int r, int c) {
    if(r == triangle.size() - 1) {
        return triangle[r][c];
    }
    if( memo.count({r,c}) > 0 ) {
        return memo[{r,c}];
    }
    int down = minimum_triangle_recursive(triangle, r+1, c);
    int down_right = minimum_triangle_recursive(triangle, r+1, c+1);
    memo[{r, c}] = triangle[r][c] + std::min(down, down_right);
    return memo[{r, c}];
} 



int main() {
    std::vector<std::vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int result = minimum_triangle(triangle);
    std::cout << "result: " << result << std::endl;

    result = minimum_triangle_recursive(triangle, 0, 0);
    std::cout << "result-recursive: " << result << std::endl;
    //Output: 11

    triangle = {{-10}};
    result = minimum_triangle(triangle);
    std::cout << "result: " << result << std::endl;

    result = minimum_triangle_recursive(triangle, 0, 0);
    std::cout << "result-recursive: " << result << std::endl;
    //Output: -10    
    return 0;
}
