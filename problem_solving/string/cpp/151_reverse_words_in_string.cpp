/*
#https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
traverse the string from 
'''
Approach I) no extra space
    reverse the string.. getting rid of spaces.
    now for each word, reverse.
    cleanspace()
    use std::swap

space: O(1)
time: O(n)

Approach II) using stringstream to separate out the words.
            put in stack... and pop from stack and add to result.
    space: O(n)
    time: O(n)

*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include <sstream>
#include<stack>

std::string reverse_words_in_string_extraspace(const std::string& input) {
    std::stringstream ss(input);
    std::stack<std::string> words;
    std::string word;
    while ( ss  >> word ) {
        words.push(word);
    }   
    std::string result;
    while(!words.empty()) {
        result += words.top();
        words.pop();
        if(!words.empty()) {
            result += " ";
        }
    }

    return result;
}

std::string reverse_words_in_string_no_extraspace(const std::string& input) {
    return input;
}



int main() {
    std::string s = "a good   example";
    std::string result = reverse_words_in_string_extraspace(s);
    std::cout << "reverse_words_in_string_code: " << result << std::endl;

    s = "the sky is   blue";
    result = reverse_words_in_string_extraspace(s);
    //#Output: "blue is sky the"
    std::cout << "reverse_words_in_string_code: " << result << std::endl;

    s = "  hello world  ";
    //#Output: "world hello"
    //#Explanation: Your reversed string should not contain leading or trailing spaces.
    result = reverse_words_in_string_extraspace(s);
    std::cout << "reverse_words_in_string_code: " << result << std::endl;

    //#Output: "example good a"
    //#Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

}