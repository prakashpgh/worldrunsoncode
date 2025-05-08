'''
https://leetcode.com/problems/basic-calculator

Idea...
    read the expression from right.
    closing brackets... push to stack.
    operands / operators .. push to stack
    operands => read the whole number

    opening brackets... evaluate the stack
'''

int evaluation_expression(const std::string& s) {
    int result = 0;
    return result; 
}

def evaluate_expression(stack):
    if not stack or type(stack[-1]) == str:
        stack.append(0)
    res = stack.pop()
    while stack and stack[-1] != ")":
        sign = stack.pop()
        if sign == "+":
            res += stack.pop()
        else:
            res -= stack.pop()
    return res

#
def calculate(s:str) ->int:
    stack = []
    n,operand=0,0
    
    for i in range(len(s)-1, -1, -1):
        ch = s[i]
        if ch.isdigit():
            operand = (10**n * int(ch)) + operand
            n+=1
        elif ch != " ":
            if n:
                stack.append(operand)
                n, operand = 0,0
            if ch == "(":
                res =evaluate_expression(stack)
                stack.pop()  #pop the )
                stack.append(res)
            else:
                stack.append(ch)
    if n:
        stack.append(operand)            
    return evaluate_expression(stack)

            
int main() {
    std::string s = "1 + 1";
    //#Output: 2
    int result = calculate(s);
    std::cout << "result: " (result) << std::endl;

    s = " 2-1 + 2 ";
    #Output: 3;
    result = calculate(s);
    std::cout << "result: " (result) << std::endl;

    s = "(1+(4+5+2)-3)+(6+8)";
    #Output: 23;
    result = calculate(s);
    std::cout << "result: " (result) << std::endl;
}

