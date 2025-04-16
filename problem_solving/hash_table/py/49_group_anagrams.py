'''
https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150

create frequency counter... 
dict[tuple of freq. counter] = Lis

'''
from collections import defaultdict

#O(m * n)
def group_anagrams(strs:list[str])->list[list[str]]:
    result_hash = {}
    for st in strs:
        count = [0]*26
        for s in st:
            count[ord(s) - ord('a')] += 1    
        t = tuple(count)        #we need tuple as key
        if t in result_hash:
            result_hash[t].append(st) 
        else:
            result_hash[t] = [st]

    return list(result_hash.values())   #mistake ... need to change this to list


strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
result = group_anagrams(strs)
print("result: " + str(result))


strs = [""]
result = group_anagrams(strs)
print("result: " + str(result))

