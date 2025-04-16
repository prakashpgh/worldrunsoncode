'''
https://leetcode.com/problems/jewels-and-stones/description/

set out of jewels.
check in stones from dictionary
'''

#TO(n+m)
#S(1)
def jewels_in_stones(jewels: str, stones: str)->list[str]:
    result = []
    hash = set()
    for j in jewels:
        hash.add(j)
    for s in stones:
        if s in hash:
            result.append(s)
    return len(result)

jewels = "aA"
stones = "aAAbbbb"
result = jewels_in_stones(jewels, stones)
print("result: " + str(result))


jewels = "z"
stones = "ZZ"
result = jewels_in_stones(jewels, stones)
print("result: " + str(result))
