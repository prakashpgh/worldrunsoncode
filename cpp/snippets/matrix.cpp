/*
matrix
*/
#include <vector>
#include<iostream>
#include "../utils/utils.h"


void transpose_matrix(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i) {
        for(int j = i+1; j < cols; ++j )
        {   
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
}

void vertical_reflection(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols/2; ++j) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][cols-j-1];
            matrix[i][cols-j-1]=tmp;
        }
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    std::cout << "before transpose " << std::endl;
    print_vector_of_vector(matrix);
    transpose_matrix(matrix);
    std::cout << "after transpose " << std::endl;
    print_vector_of_vector(matrix);
    vertical_reflection(matrix);
    std::cout << "after vertical reflection " << std::endl;
    print_vector_of_vector(matrix);
    return 0;
}
