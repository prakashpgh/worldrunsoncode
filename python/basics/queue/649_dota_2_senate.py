'''
https://leetcode.com/problems/dota2-senate/

use of q.
maintain 2 different qs... fill the indexes r and d in the q
traverse the qs... pop(),  the one with lowers index... append i+N... 
basically we are removing the one with later index from the q...
final result: the q that remains is the winner
'''
from collections import deque

def predict_party_victory(senate: str) -> str:
    rq = deque()
    dq = deque()
    N=len(senate)

    for i in range(N):
        if senate[i] == "R":
            rq.append(i)
        else:
            dq.append(i)
    while dq and rq:
        di = dq.popleft()
        ri = rq.popleft()
        if di < ri:
            dq.append(di + N)
        else:
            rq.append(ri + N)

    if rq:
        return "Radiant"
    else:
        return "Dire"


senate = "RD"
#Output: "Radiant"
result = predict_party_victory(senate)
print("result=" + result)

senate = "RDD"
#Output: "Dire"
result = predict_party_victory(senate)
print("result=" + result)
