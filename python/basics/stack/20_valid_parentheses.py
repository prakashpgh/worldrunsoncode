'''
https://leetcode.com/problems/valid-parentheses/description/

use of stack
map of closing to opening bracket
when you encounter a closing bracket - pop up from stack and the bracket should match
    at the end the stack should be empty
'''
def valid_parentheses(input:str):
    bracketmap = {")":"(", "]":"[", "}":"{"}
    result = False

    stk = []
    for c in input:
        if c not in bracketmap.keys():
            stk.append(c)
        else:
            if len(stk) == 0:
                return False
            pop = stk.pop()
            if pop != bracketmap[c]:
                return False
    return len(stk) == 0


input = "()"
result = valid_parentheses(input)
print("result: " + str(result))
#true


input = "()[]{}"
result = valid_parentheses(input)
print("result: " + str(result))

#true

input = "(]"
result = valid_parentheses(input)
print("result: " + str(result))
#false

input = "([])"
result = valid_parentheses(input)
print("result: " + str(result))

#true