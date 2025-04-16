/*
https://leetcode.com/problems/valid-parentheses/

iterate the string
when closing brace is encountered, check if the top of stack has the correcsponding opening, if yes, pop, if no, return false.
for opening brackets, push the stack.
in the end the stack should be empty for success.
*/
#include<stack>
#include<unordered_map>
#include<iostream>

bool valid_parentheses(const std::string& s) {
    std::unordered_map<char, char> braces = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    std::stack<char> st;
    for( const auto ch : s ) {
        //end brace found...
        if(braces.find(ch) != braces.end() ) {
            if(st.empty()) {
                return false;
            }
            auto top = st.top();
            if(braces[ch] != top ) {
                return false;
            }
            st.pop(); 
        } else {
            st.push(ch);
        }
    }
    if (st.empty()) {
        return true;
    }
    return false;
}


int main() {
    std::string s = "()";
    bool result = valid_parentheses(s);
    std::cout << "result: " << result << std::endl;
    //Output: true


    s = "()[]{}";
    result = valid_parentheses(s);
    std::cout << "result: " << result << std::endl;
    //Output: true

    s = "(]";
    result = valid_parentheses(s);
    std::cout << "result: " << result << std::endl;
    //Output: false

    s = "([])";
    result = valid_parentheses(s);
    std::cout << "result: " << result << std::endl;
    //true

    return 0;
}