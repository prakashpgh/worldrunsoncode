/*
https://leetcode.com/problems/add-digits/

2 while loops.
    outer while loop => number less than 10
        inner while loop... extract the digits and sum up to create the next number.
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>
#include<algorithm>
using namespace std;


int add_digits(int num) {
    
    while(num > 9) {
        int new_number = 0;
        while(num > 0) {
            new_number += num % 10;
            num /= 10;
        }
        num = new_number;
    }
    return num;
}

int main () {
    int n = 38;
    int result = add_digits(n);
    std::cout << "result: " << result << std::endl;
}