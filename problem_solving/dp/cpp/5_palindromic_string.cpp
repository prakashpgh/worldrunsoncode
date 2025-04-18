/*
https://leetcode.com/problems/longest-palindromic-substring

iterate the string..
for each char, consider that as the center of palindrom... 
    check if its a palindrome from center... and if has the max length, get the max string.
*/


#include<string>
#include<vector>
#include<iostream>

std::string longest_palindromic_string(const std::string& s) {
    int len = s.length();
    int max_len = 0;
    std::string longest_palin;
    for(int i = 0; i < len; ++i) {
        int l = i;
        int r = i;
        while(l >= 0 && r < len && s[l]==s[r]) {
            l -= 1;
            r += 1;
        }
        l += 1;
        r -= 1;
        std::cout << l << "," << r << std::endl;
        if(max_len < r-l+1) {
            max_len = r-l+1;
            longest_palin = s.substr(l, r-l+1);
            //std::cout << l << "," << r << " string "<< longest_palin << std::endl;
        }
        

        //even case.
        l = i;
        r = i+1;
        while(l >= 0 && r < len && s[l]==s[r]) {
            l -= 1;
            r += 1;
        }
        l += 1;
        r -= 1;
        std::cout << l << "," << r << std::endl;
        if(max_len < r-l+1) {
            max_len = r-l+1;
            longest_palin = s.substr(l, r-l+1);
            //std::cout << l << "," << r << " string "<< longest_palin << std::endl;
        }
    }
    return longest_palin;
}


int main() {
    std::string s = "babad";
    std::string result = longest_palindromic_string(s);
    std::cout << "result: " << result << std::endl;

    s = "cbbd";
    result = longest_palindromic_string(s);
    std::cout << "result: " << result << std::endl;
    return 0;
}
