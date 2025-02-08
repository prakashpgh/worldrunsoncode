#https://leetcode.com/problems/koko-eating-bananas/
from math import ceil

def koko_eating_bananas(piles, hours):
    result = 1
    l = 1
    
    M = max(piles)
    r = M
    while r > l:#did mistake here, went into loop
        m = (l+r)//2
        h_taken = 0
        for p in piles:
            h_taken += ceil(p/m)
        if h_taken > hours:
            l = m+1
        if h_taken <= hours:    
            r = m #did mistake here
    return r




piles = [3,6,7,11]
h = 8
result = koko_eating_bananas(piles, h)
print("result: " + str(result))

piles = [30,11,23,4,20]
h = 5
#Output: 30
result = koko_eating_bananas(piles, h)
print("result: " + str(result))


piles = [30,11,23,4,20]
h = 6
#Output: 23
result = koko_eating_bananas(piles, h)
print("result: " + str(result))
