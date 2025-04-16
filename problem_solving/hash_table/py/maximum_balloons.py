#T O(n)
#S O(1)
from collections import defaultdict
def max_balloons(input):
    hash = defaultdict(int)
    balloon = "balloon"
    for c in input:
        if c in balloon:
            hash[c] += 1

    print("hash: " + str(hash))
    if any(c not in hash for c in balloon):
        print("not in")
        return 0
    else: 
        print("in")
        return min(hash["b"], hash["a"], hash["l"]//2, hash["o"]//2, hash["n"])


input = "nlaebolko"
result = max_balloons(input)
print("result: " + str(result))


input = "loonbalxballpoon"
result = max_balloons(input)
print("result: " + str(result))