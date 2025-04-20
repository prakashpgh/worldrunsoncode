/*
https://leetcode.com/problems/reverse-bits/
*/
#include<iostream>
#include<string>

uint32_t reverse_bits(uint32_t n) {
    uint32_t result = 0;
    for(int i = 0; i < 31; ++i) {
        uint32_t u = (n >> i) & 1;
        result |= u << (31 - i);
    }
    return result;
}

#include<bitset>

int main() {
    uint32_t num1 = 43261596;
    std::bitset<32> binary(num1);
    std::cout << binary.to_string() << std::endl;

    auto rev = reverse_bits(num1);
    std::cout << rev << std::endl;

    binary = rev;
    std::cout << binary.to_string() << std::endl;
    return 0;
}