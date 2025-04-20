/*
https://leetcode.com/problems/number-of-1-bits/

    x & (x-1) => removes the rightmost bit 
*/
#include<iostream>

int count_1_bits(int num) {
    int bits = 0;
    while (num != 0) {
        num = num & (num - 1);
        bits += 1;
    }
    return bits;
}


int main() {
    int n = 11;
    int result = count_1_bits(n);
    std::cout << "result: " << result << std::endl;

    n = 128;
    //Output: 1
    result = count_1_bits(n);
    std::cout << "result: " << result << std::endl;

    n = 2147483645;
    //utput: 30
    result = count_1_bits(n);
    std::cout << "result: " << result << std::endl;
    return 0;
}