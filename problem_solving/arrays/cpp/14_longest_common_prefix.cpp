/*
'''
https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150

for loop => iterate over the characters of first string..
    for loop => iterate ove the strings starting from 1, 
        => check for lenght and the characte match.

    if array is 0 or 1.

*/

//#T(m * n) m = min. length
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<string>
#include<vector>

#todo
std::string longest_common_prefix(const std::vector<std::string>& strs) {
    std::string result;

    return result;
}



int main() {
    std::vector<std::string> strs;
    strs = {"cir", "car"};
    std::string prefix = longest_common_prefix(strs);
    print_vector(strs);
    std::cout << "prefix:" << " => " << prefix << std::endl;


    strs = {"flower", "flow", "flight"};
    prefix = longest_common_prefix(strs);
    print_vector(strs);
    std::cout << "prefix:" << " => " << prefix << std::endl;

    strs = {"dog", "racecar", "car"};
    prefix = longest_common_prefix(strs);
    print_vector(strs);
    std::cout << "prefix:" << " => " << prefix << std::endl;

    strs = {"flower", "flowz", "flow"};
    prefix = longest_common_prefix(strs);
    print_vector(strs);
    std::cout << "prefix:" << " => " << prefix << std::endl;

    strs = {""};
    prefix = longest_common_prefix(strs);
    print_vector(strs);
    std::cout << "prefix:" << " => " << prefix << std::endl;
}