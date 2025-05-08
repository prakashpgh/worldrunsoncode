/*
'''
https://leetcode.com/problems/evaluate-reverse-polish-notation
if operands, put in stack
if operator, pop top two, and apply the operator
end result will be in the stack
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


int evaluate_reverse_polish_notation(const std::vector<std::string>& tokens ) {
    int result = 0;
    return result;
}



int main() {
    std::vector<std::string> tokens = {"2","1","+","3","*"};
    int result = evaluate_reverse_polish_notation(tokens);
    std::cout << "result: " << result << std::endl;
    //#9


    tokens = {"4","13","5","/","+"};
    result = evaluate_reverse_polish_notation(tokens);
    std::cout << "result: " << result << std::endl;
    //#6

    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    result = evaluate_reverse_polish_notation(tokens);
    std::cout << "result: " << result << std::endl;
    //#22

}

