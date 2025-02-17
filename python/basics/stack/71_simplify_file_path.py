'''
https://leetcode.com/problems/simplify-path/description/
use of stack
    .. => pop
    no token or . => ignore
'''

def simplify_path(path:str) -> str:
    stack = []
    tokens = path.split("/")
    for token in tokens:
        if token == "..":
            if stack:
                stack.pop()
        elif not token or token == ".": #mistake missed not token
            continue
        else:
            stack.append(token)
    return "/" + "/".join(stack)#mistake missed "/"





path = "/home/"
#"/home"
new_path = simplify_path(path)
print("new_path: " + new_path)


path = "/home//foo/"
#"/home/foo"
new_path = simplify_path(path)
print("new_path: " + new_path)


path = "/home/user/Documents/../Pictures"
#Output: "/home/user/Pictures"
new_path = simplify_path(path)
print("new_path: " + new_path)


path = "/../"
#Output: "/"
new_path = simplify_path(path)
print("new_path: " + new_path)


path = "/.../a/../b/c/../d/./"
#Output: "/.../b/d"
new_path = simplify_path(path)
print("new_path: " + new_path)
