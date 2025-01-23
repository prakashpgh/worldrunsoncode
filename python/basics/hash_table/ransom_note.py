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



magazine="ab"
note="aab"
result = ransom_note(magazine, note)
print("result:" + str(result))

magazine="aba"
note="aab"
result = ransom_note(magazine, note)
print("result:" + str(result))
