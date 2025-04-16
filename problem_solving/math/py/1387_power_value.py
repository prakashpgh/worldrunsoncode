'''
https://leetcode.com/problems/sort-integers-by-the-power-value/description/

order:
calc with memoization: O(N)
heap push: N*log

space: dictionary space: N, heap space N. effective order is O(N)
'''

class Pair:
    def __init__(self, num, val):
        self.num = num
        self.val = val

    def __lt__(self, other:"Pair"):
        return self.val < other.val or (self.val == other.val and self.num < other.num )
    
import heapq

def get_kth_power_value(lo: int, hi: int, k: int) -> list[int]:

    cache = {}
    def get_power_value(x):
        if x in cache:
            return cache[x]
        if x == 1:
            return 0
        val = 0
        if x % 2 == 0:
            val = 1 + get_power_value(x/2)
        else:
            val = 1 + get_power_value(3*x + 1)
        cache[x] = val
        return cache[x]


    #find power values... store in hash (value, x)
    min_hash = []
    for i in range(lo, hi+1):
        power = get_power_value(i)
        heapq.heappush(min_hash, (power, i))
    return min_hash[k-1][1]
    #sort by value and x.. and put it in a min hash





lo = 12
hi = 15
k = 2
#Output: 13
result = get_kth_power_value(lo, hi, k)
print(result)


lo = 7
hi = 11
k = 4
#Output: 7
result = get_kth_power_value(lo, hi, k)
print(result)
