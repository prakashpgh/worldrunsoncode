/*
#https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
traverse the string from 
'''

Approach I) no extra space
    reverse the string.. getting rid of spaces.
        
        writer pointer...
        reader pointer => till it gets non-space
        write the word..
        reverse..
        space..

        std::revese

        resize
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

/*
1) reverse the string..   std::reverse(xx.begin(), xx.end())
2) get rid of the extra space... reverse the word...
*/
std::string reverse_words_in_string_no_extraspace(std::string& input) {
    int r = 0;
    int w = 0;
    //remove spaces
    while(r < input.length() && input[r] == ' ') {
        r++;
    }
    while(r < input.length()) {
        //traverse the word
        while(r < input.length() && input[r] != ' ') {
            input[w++] = input[r++];
        }   
        if(r < input.length()) {
            input[w++] = ' ';
        }
        //skip the spaces between words..
        while(r < input.length() && input[r] == ' ') {
            r++;
        }
    }
    input.resize(j);

    if(input.empty()) {
        return "";
    }

    if(input.back() == ' ') {
        input.pop_back();
    }

    if(input.empty()) {
        return "";
    }
    ////by this time all extra spaces have been removed.
    //reverse the string.
    std::reverse(input.begin(), input.end());

    int word_start = 0;
    for(int i=0; i <= input.length(); ++i) {
        if( i == input.length() || input[i] == ' ') {
            std::reverse(input.begin() + word_start, input.begin() + i);
            word_start = i + 1;
        }
    }
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