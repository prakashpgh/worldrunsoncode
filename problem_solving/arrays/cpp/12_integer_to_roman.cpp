/*
'''
https://leetcode.com/problems/integer-to-roman/description/
we have a list of tuples.. starting from 1000 to 1
use divmod function to find quotient and reminder
q * the mapping,  num = r
'''

mapping = [(1000,'M'), (900,'CM'), (500, 'D'), (400, 'CD'), (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'), (10, 'X'), (9,'IX'), (5,'V'), (4,'IV'), (1,'I') ]

create the map from int => roman


*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


//#todo
std::string int_to_roman(int num) {
    std::string result;
    std::vector<std::pair<int, std::string>> mapping = {
        {1000,"M"}, 
        {900,"CM"}, 
        {500, "D"}, 
        {400, "CD"}, 
        {100, "C"}, 
        {90, "XC"}, 
        {50, "L"}, 
        {40, "XL"}, 
        {10, "X"}, 
        {9,"IX"},
        {5,"V"}, 
        {4,"IV"}, 
        {1,"I"}
    };

    for(const auto& pair : mapping) {
        while( num > pair.first ) {
            num -= pair.first;
            result += pair.second;
        }
    }

    return result;
}


int main() {
    int num = 3749;
    //#Output: "MMMDCCXLIX"
    std::string result = int_to_roman(num);
    std::cout << "result: " << result << std::endl;

    num = 58;
    //#Output: "LVIII"
    result = int_to_roman(num);
    std::cout << "result: " << result << std::endl;


    num = 1994;
    //#Output: "MCMXCIV"
    result = int_to_roman(num);
    std::cout << "result: " << result << std::endl;


    num = 49;
    //#Output: "XLIX";
    result = int_to_roman(num);
    std::cout << "result: " << result << std::endl;
    return 0;
}