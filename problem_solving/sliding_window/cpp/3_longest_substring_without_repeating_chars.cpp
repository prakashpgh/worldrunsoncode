/*
*/
#include<string>
#include<unordered_map>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


int longest_substring_without_repeating_chars(const std::string& s) {
    int sl = s.length();
    int l = 0;
    int max_len = 0;
    std::unordered_map<char, int> chars_index;
    for(int i = 0; i < sl; ++i) {
        if(chars_index.find(s[i]) != chars_index.end() && l <= chars_index[s[i]]) {
            l = chars_index[s[i]] + 1;
        }
        chars_index[s[i]] = i;
        max_len = std::max(max_len, i-l+1);
    }
    return max_len;
}



int main() {
    std::string s = "abcabcbb";
    //Output: 3
    int result = longest_substring_without_repeating_chars(s);
    std::cout << "result: " << result << std::endl;


    s = "bbbbb";
    //Output: 1
    result = longest_substring_without_repeating_chars(s);
    std::cout << "result: " << result << std::endl;

    s = "pwwkew";
    //Output: 3
    result = longest_substring_without_repeating_chars(s);
    std::cout << "result: " << result << std::endl;

    return 0;
}