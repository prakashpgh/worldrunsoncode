'''
https://leetcode.com/problems/decode-string/

Idea: use stack
till [ starts, keep constructing current str and current number
once [ start, stash current_str and current_number into stack.
once you encounter closing ], pop from stack, multiply the current str by the numbe and add to the stack string... to make your new current_Str
result is current_str
'''

def decode_string(s: str) -> str:
    stack = []
    current_number = 0
    current_str = ""
    for ch in s:
        if ch.isdigit():
            current_number = current_number*10 + int(ch)
        elif ch == "[":
            stack.append((current_number, current_str))
            current_str = "" 
            current_number = 0
        elif ch == "]":
            (num, previous_str) = stack.pop()
            current_str = previous_str + num * current_str
        else:
            current_str += ch
    return current_str





s = "3[a]2[bc]"
#Output: "aaabcbc"
result = decode_string(s)
print("result=" + str(result))

s = "3[a2[c]]"
#Output: "accaccacc"
result = decode_string(s)
print("result=" + str(result))


s = "2[abc]3[cd]ef"
#Output: "abcabccdcdcdef"
result = decode_string(s)
print("result=" + str(result))
