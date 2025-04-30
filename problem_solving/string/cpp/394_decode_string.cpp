/*'''
https://leetcode.com/problems/decode-string/

Idea: use stack
till [ starts, keep constructing current str and current number
once [ start, stash current_str and current_number into stack.
once you encounter closing ], pop from stack, multiply the current str by the numbe and add to the stack string... to make your new current_Str
result is current_str
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


std::string decode_string(const std::string& input) {
    std::stack<std::pair<int, std::string>> st;
    int len = input.length();
    int current_num = 0;
    std::string current_str = "";
    for(int i = 0; i < len; ++i) {
        char ch = input[i];
        if(std::isdigit(ch)) {
            current_num = current_num * 10 + (ch - '0');
        } else if(ch == '[') {
            st.push({current_num, current_str});
            current_str = "";
            current_num = 0;
        } else if(ch == ']') {
            const auto& pair = st.top();
            st.pop();
            std::string s;
            for(int i = 0; i < pair.first; ++i) {
                s += current_str;
            }
            current_str = pair.second + s;
        } else {
            current_str += ch;
        }
    }
    return current_str;
}


int main() {
    std::string s;
    s = "3[a]2[bc]";
    //#Output: "aaabcbc";
    std::string result = decode_string(s);
    std::cout << "result=" << result << std::endl;

    s = "3[a2[c]]";
    //#Output: "accaccacc";
    result = decode_string(s);
    std::cout << "result=" << result << std::endl;


    s = "2[abc]3[cd]ef";
    ///#Output: "abcabccdcdcdef";
    result = decode_string(s);
    std::cout << "result=" << result << std::endl;
}