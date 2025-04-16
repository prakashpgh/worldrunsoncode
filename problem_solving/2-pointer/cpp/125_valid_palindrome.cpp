/*
 
 * 
 */


#include<string>
#include<cctype>
#include<iostream>
using namespace std;

bool is_palindrome(const std::string& s) {
    int l = 0;
    int r = s.length()-1;
    while(l < r) {
        while(l < r && !std::isalnum(s[l])) {
            l += 1;
        }
        while(l < r && !std::isalnum(s[r])) {
            r -= 1;
        }
        if(l < r && std::tolower(s[l]) != std::tolower(s[r])) {
            return false;
        }
        l += 1;
        r -= 1;
    }
    return true;
}


int main() {
    std::string s = "A man, a plan, a canal: Panama";
    //Output: true
    std::cout << "is_palindrome:" << std::endl;
    bool result = is_palindrome(s);
    cout << result << std::endl;

    s = "race a car";
    //Output: false
    std::cout << "is_palindrome:" << std::endl;
    result = is_palindrome(s);
    cout << result << std::endl;


    s = " ";
    //Output: true
    std::cout << "is_palindrome:" << std::endl;
    result = is_palindrome(s);
    cout << result << std::endl;

    return 0;
}