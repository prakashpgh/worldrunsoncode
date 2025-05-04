/*
'''
https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

here the catch is when you change the col+row to zero, then it affects the existing 1s as well.

Option 1) make a read-only copy, and change the input

Option 2) 
        1st row and 1st column are used as flags for the rows and cols zero... 
        flag kept if the 1st column has to be zerod.
        iterate by exclusing the 1st row and 1st column, and update the 1st row and 1st column

        go thru the 1st row and 1st column and update the zeros
        check 0,0,, and update the 1st rows..
        check the 1st column flag and update the 1st column accordingly
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>

void set_zeros(std::vector<std::vector<int>>& matrix) {

}


int main() {
    std::vector<std::vector<int>> matrix;
    matrix = {{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
    set_zeros(matrix);
    
    
    matrix = {{1,1,1},
              {1,0,1},
              {1,1,1}};
    set_zeros(matrix);
}


