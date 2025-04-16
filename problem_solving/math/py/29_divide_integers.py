'''
https://leetcode.com/problems/divide-two-integers/

keep subtracting divisor from dividend till dividend >= divisor
    optimization: we can increase the divisor and multiple
'''

def divide(dividend: int, divisor: int) -> int:
    sign = 1
    if (dividend < 0 ) ^ (divisor < 0):
        sign = -1
    if dividend == -2147483648 and (divisor == -1):
        return 2147483647        
    if dividend == -2147483648 and (divisor == 1):
        return -2147483648        
# Constants.
    MAX_INT = 2147483647  # 2**31 - 1
    MIN_INT = -2147483648  # -2**31

    dividend = abs(dividend)
    divisor = abs(divisor)
    # Special case: overflow.
    if dividend == MIN_INT and divisor == -1:
        return sign * MAX_INT    

    quotient = 0
    while dividend >= divisor:
        temp = divisor
        multiple = 1
        while dividend >= (temp << 1):
            temp <<= 1
            multiple <<= 1
        
        dividend -= temp
        quotient += multiple
        if quotient > 2**31 -1:
            quotient = 2**31 -1
    return sign * quotient





dividend = 10
divisor = 3
result = divide(dividend, divisor)
print("result: " + str(result))

