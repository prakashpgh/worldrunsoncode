/*
'''
https://leetcode.com/problems/roman-to-integer/description/
#time: O(n)
#space: O(1)
the main thing here is handing cases like IV  XC, 
inspect the character after you, and it current < current + 1 => value = (next - current)
'''
*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"

//todo
int roman_to_int(const std::string& roman) {
    int result = 0;
    std::unordered_map<std::string, int> mapping = 
            { 
                {"M",1000} , 
                {"D",500}, 
                {"C",100}, 
                {"L",50}, 
                {"X",10}, 
                {"V",5},  
                {"I", 1}
            };

    return result;
}

int main() {
    std::string roman ="MCMXCIV";
    int whole_number = roman_to_int(roman);
    std::cout << "whole_number:" << whole_number << std::endl;
    return 0;
}

