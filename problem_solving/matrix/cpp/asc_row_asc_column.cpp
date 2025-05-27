/*
asc. row and asc. column
*/
#include <vector>
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


std::pair<int, int> search(const std::vector<std::vector<int>>& matrix, int n)  {
    std::pair<int, int> result;
    //start from top-right.
    int rows = matrix.size();
    int cols = 0;
    if(rows > 0) {
        cols = matrix[0].size();
    }
    int r = 0;
    int c = cols - 1;
    while(r < rows && c >= 0)  {
        if(matrix[r][c] == n) {
            return {r, c};
        }
        while(c >= 0 && matrix[r][c] > n) {
            if(matrix[r][c] == n) {
                return {r, c};
            }
            c--;
        }
        while(r < rows && matrix[r][c] < n) {
            if(matrix[r][c] == n) {
                return {r, c};
            }
            r++;
        }
    }
    return {-1,-1};
}


int main() {
    std::vector<std::vector<int>> matrix = {
        {1,2,300},
        {4,5,400},
        {6,7,500}
    };
    int n = 5;
    auto result = search(matrix, n);
    std::cout << "result " << result.first << " => " << result.second << std::endl;
}
