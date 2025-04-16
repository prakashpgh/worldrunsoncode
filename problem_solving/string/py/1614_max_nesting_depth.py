'''
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

push the "(" to stack, if we encounter ")" pop from stack

'''

def min_remove_parentheses_to_make_valid(s: str) -> str:
    stack = []
    remove_indexes = set()
    for i, ch in enumerate(s):
        if ch == "(":
            stack.append(i)
        elif ch == ")":
            if stack:
                stack.pop()
            else:
                remove_indexes.add(i)

    remove_indexes.update(stack)
        
    result = []
    for i, ch in enumerate(s):
        if i not in remove_indexes:
            result.append(s[i])
    return "".join(result)



s = "lee(t(c)o)de)"
#Output: "lee(t(c)o)de"
result = min_remove_parentheses_to_make_valid(s)
print("result " + result)


s = "a)b(c)d"
#Output: "ab(c)d"
result = min_remove_parentheses_to_make_valid(s)
print("result " + result)


s = "))(("
#Output: ""
result = min_remove_parentheses_to_make_valid(s)
print("result " + result)

    
