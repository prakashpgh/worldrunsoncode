'''
https://leetcode.com/problems/partition-labels/

iterate the string and keep a dictionary of start and end...

now iterate the string,
    update end.. with the end of the character..
    when i == end, the section finishes.. start a new section    

'''


def partition_labels(s: str):
    if not s:
        return s
    result = []
    markers = {}
    for i in range(len(s)):
        if s[i] not in markers:
            markers[s[i]] = i
        else:
            markers[s[i]] = i

    start = 0
    end = 0
    for i, c in enumerate(s):
        end = max(end, markers[c])
        if i == end:
            result.append(end - start + 1)
            start = i+1
    return result

    


s = "ababcbacadefegdehijhklij"
result = partition_labels(s)
print("result= " + str(result))


s = "eccbbbbdec"
#Output: [10]
result = partition_labels(s)
print("result= " + str(result))
