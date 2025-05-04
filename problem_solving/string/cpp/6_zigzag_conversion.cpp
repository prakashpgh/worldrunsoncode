/*
'''
https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150

create a list of lists... like a matrix
    from the string, enter the words in to the matrix
    do a join    
'''
in c++ vector of strings.. direction = -1... change direction when r=0 or r = lastrow.
*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"

#todo
std::string zigzag_conversion(const std::string& s, int rows) {
    std::string result;
    return result;
}


int main() {
    std::string input;
    input = "PAYPALISHIRING";
    int rows = 3;
    std::string output = zigzag_conversion(input, rows);
    std::cout << "output: " << output << std::endl;
    //#PAHNAPLSIIGYIR


    rows = 4;
    output = zigzag_conversion(input, rows);
    std::cout << "output: " << output << std::endl;
    //#PINALSIGYAHRPI

    input = "A";
    rows = 1;
    //#A
    output = zigzag_conversion(input, rows);
    std::cout << "output: " << output << std::endl;
}



