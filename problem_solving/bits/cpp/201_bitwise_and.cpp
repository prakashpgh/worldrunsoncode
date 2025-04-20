/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/

Idea is we have to look out for the bits where bits of all the numbes are in range.
and its the same bit for the first and the last in the range.

Approach I: keep right shifting m & n by 1 till m==n.  now left shift by the same total_shifts
        9-12
        1001
        1100
            right shift by 3 makes them equal.
            left shift by 3 = 8

Approach II: getting rid of the right bits
    get rid of the right 1s by  =>  n & (n-1)
*/
#include<iostream>

int bitwise_and_range(int left, int right) {
    int shifts = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        shifts += 1;
    }
    left <<= shifts;
    return left; 
}

int bitwise_and_range_chop_right_bits(int left, int right) {
    while (left < right) {
        right = right & (right -1);
    }
    return right;
}



int main() {
    int left = 5;
    int right = 7;
    int result = bitwise_and_range(left, right);
    std::cout << "result: " << result << std::endl;

    result = bitwise_and_range_chop_right_bits(left, right);
    std::cout << "result: " << result << std::endl;
    
}
