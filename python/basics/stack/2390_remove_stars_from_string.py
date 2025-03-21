'''
https://leetcode.com/problems/removing-stars-from-a-string/
'''


def remove_star_from_string(s: str):
    stack = []
    for ch in s:
        if stack and ch == '*':
            stack.pop() 
        else:
            stack.append(ch)
    return "".join(stack)


s = "leet**cod*e"
#Output: "lecoe"
result = remove_star_from_string(s)
print("result: " + str(result))

s = "erase*****"
#Output: ""
result = remove_star_from_string(s)
print("result: " + str(result))
