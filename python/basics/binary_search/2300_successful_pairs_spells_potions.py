'''
https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

for each, spell, do a binary search
t: O( (m+n) * log(m) )  => sorting: mlogm   binarysearch: n * logm
s: 
'''

def successful_pairs_spells_potions(spells: list[int], potions: list[int], success: int) -> list[int]:
    potions.sort()
    result = []
    for s in spells:
        target = success / s
        l = 0
        r = len(potions)-1
        while l <= r:
            m = l + (r-l)//2
            if target > potions[m]:
                l = m + 1
            else:
                r = m - 1
        pairs = len(potions)-l
        result.append(pairs)
    return result



spells = [5,1,3]
potions = [1,2,3,4,5]
success = 7
#Output: [4,0,3]
result = successful_pairs_spells_potions(spells, potions, success)
print("result= " + str(result))



spells = [3,1,2]
potions = [8,5,8]
success = 16
#Output: [2,0,2]
result = successful_pairs_spells_potions(spells, potions, success)
print("result= " + str(result))
