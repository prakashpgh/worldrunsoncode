'''
https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

for the magazine, create the counter dictionary of counts
iterate the ransom note, and keep chaning the counter,  if something is not found, then false
'''
from collections import defaultdict

def ransom_note(magazine:str, note:str)->bool:
    counter = defaultdict(int)
    for m in magazine:
        counter[m] += 1
    for n in note:
        if n not in counter or counter[n] == 0:
            return False
        else:
            counter[n] -= 1

    return True


magazine="aab"
note="aa"
result = ransom_note(magazine, note)
print("result:" + str(result))



magazine="ab"
note="aab"
result = ransom_note(magazine, note)
print("result:" + str(result))

magazine="aba"
note="aab"
result = ransom_note(magazine, note)
print("result:" + str(result))
