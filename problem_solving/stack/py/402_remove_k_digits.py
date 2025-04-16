'''
https://leetcode.com/problems/remove-k-digits

using stack..remove the larger integers esp. if they come before a smaller digit
iterate the string..
    compare with whats on top of stack.. if digit < stack top, 
        pop 
        decrement k
    append to stack.

if k > 0:
    keep popping till k = 0
    
#todo
'''

def remove_k_digits(num: str, k:int) -> str:

    return ""
