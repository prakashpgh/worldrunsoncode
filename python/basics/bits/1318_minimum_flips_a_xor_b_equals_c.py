'''
https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

we check the lsb for a, b & c.  (a & 1)
2 cases => lsb of c can be 0 or 1.
if lsb of c == 0, then lsb of a and b has to be zero.
if lsb of c == 1, then lsb of a or b should 1.
right shift to get the new lsbs
'''

def minimum_flips_a_xor_b_equals_c(a: int, b: int, c: int) -> int:
    ans = 0
    while a or b or c:
        if (c & 1):
            if (a & 1) or (b & 1):
                ans += 0
            else:
                ans += 1
        else:
            ans += (a & 1) + (b & 1)
        a >>= 1
        b >>= 1
        c >>= 1
    return ans
