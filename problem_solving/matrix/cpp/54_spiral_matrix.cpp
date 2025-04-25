/*
https://leetcode.com/problems/spiral-matrix/
*/

#include<vector>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;

vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = 0;
        if(rows > 0) {
            cols = matrix[0].size();
        }
        if(rows == 0 || cols == 0) {
            return {};
        }
        std::vector<int> result;
        int l = 0;
        int r = cols -1;
        int u = 0;
        int d = rows -1;
        while(result.size() < rows * cols) {
            for(int i = l; i <= r; ++i) {
                result.push_back(matrix[u][i]);
            }
            if(result.size() == rows * cols) {
                break;
            }
            print_vector(result);
            u += 1;
            for(int i = u; i <= d; ++i) {
                result.push_back(matrix[i][r]);
            }
            if(result.size() == rows * cols) {
                break;
            }
            print_vector(result);
            r -= 1;
            for(int i = r; i >= l; --i) {
                result.push_back(matrix[d][i]);
            }
            if(result.size() == rows * cols) {
                break;
            }
            print_vector(result);
            d -= 1;
            for(int i = d; i >= u; --i) {
                //std::cout << "r: " << i << " c: " << l << " v: " << matrix[i][l];
                result.push_back(matrix[i][l]);
            }
            if(result.size() == rows * cols) {
                break;
            }
            print_vector(result);
            l += 1;
            //std::cout << result.size() << "=>" << rows * cols << std::endl;
        }
        return result;
    }





int main() {
    std::vector<std::vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    //Output: [1,2,3,6,9,8,7,4,5]
    auto result = spiralOrder(matrix);
    print_vector(result);


    matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    //Output: [1,2,3,4,8,12,11,10,9,5,6,7]
    result = spiralOrder(matrix);
    print_vector(result);

    return 0;
}


