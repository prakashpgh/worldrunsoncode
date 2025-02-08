'''
https://leetcode.com/problems/integer-to-roman/description/
we have a list of tuples.. starting from 1000 to 1
use divmod function to find quotient and reminder
q * the mapping,  num = r
'''

mapping = [(1000,'M'), (900,'CM'), (500, 'D'), (400, 'CD'), (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'), (10, 'X'), (9,'IX'), (5,'V'), (4,'IV'), (1,'I') ]


def integer_to_roman(num: int) -> str:
    result = []
    for m in mapping:
        (q, r) = divmod(num, m[0])
        if q > 0:
            result.append(m[1]*q)
            num = r
    return "".join(result)



num = 3749
#Output: "MMMDCCXLIX"
result = integer_to_roman(num)
print("result: " + result)


num = 58
#Output: "LVIII"
result = integer_to_roman(num)
print("result: " + result)


num = 1994
#Output: "MCMXCIV"
result = integer_to_roman(num)
print("result: " + result)


num = 49
#Output: "XLIX"
result = integer_to_roman(num)
print("result: " + result)
