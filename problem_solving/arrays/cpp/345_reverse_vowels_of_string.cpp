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
    int l = 0;
    std::unordered_set<char> vowels = {'a','e','i','o','u', 'A','E','I','O','U'};
    int r = s.length() - 1;
    while(l < r) {
        while(l < r && vowels.find(s[l]) == vowels.end() ) {
            l++;
        }
        while(l < r && vowels.find(s[r]) == vowels.end() ) {
            r--;
        }
        if(l < r) {
            std::swap(s[l], s[r]);
            l++;
            r--;
        }
    }
    return s;
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