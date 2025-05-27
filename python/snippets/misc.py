#random
import random

r = random.randint(0,10)
print("r=" + str(r))


# binary search
import bisect
b=[1,2,3,4,5,6,7,8]
result = bisect.bisect_left(b, 2)
print("result: " + str(result))
