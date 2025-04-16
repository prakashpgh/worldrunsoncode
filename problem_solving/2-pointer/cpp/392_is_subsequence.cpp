/*
https://leetcode.com/problems/is-subsequence/
 */

#include<string>
#include<iostream>
#include "../../utils/utils.h"


 bool is_subsequence(const std::string& s, const std::string& t) {
    if(s.empty()) {
        return true;
    }
    int k = 0;
    int len_t = t.length();
    int len_s = s.length();
    for (int i = 0; i < len_t; ++i) {
        if (t[i] == s[k]) {
            k += 1;
            if(k==len_s) {
                return true;
            }
        }
    }
    return false;
}


 int main() {
    std::string s = "abc";
    std::string t = "ahbgdc";
    //Output: true
    auto result = is_subsequence(s, t);
    std::cout << "result: " << result << std::endl;

    s = "";
    t = "ahbgdc";
    //Output: true
    result = is_subsequence(s, t);
    std::cout << "result: " << result << std::endl;

    s = "a";
    t = "c";
    //Output: false
    result = is_subsequence(s, t);
    std::cout << "result: " << result << std::endl;

    s = "axc";
    t = "ahbgdc";
    //Output: false
    result = is_subsequence(s, t);
    std::cout << "result: " << result << std::endl;
  
 }