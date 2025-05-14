/*
'''
https://leetcode.com/problems/reverse-vowels-of-a-string/
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


string reverse_vowels(std::string s) {
    std::string result;
    return result;
}



int main() {
    std::string s = "IceCreAm";
    //#Output: "AceCreIm"
    std::string result = reverse_vowels(s);
    std::cout << result << std::endl;

    s = "leetcode";
    //#Output: "leotcede"
    result = reverse_vowels(s);
    std::cout << result << std::endl;
}