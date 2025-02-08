'''
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
'''

def strstr(haystack: str, needle: str):
    m = len(haystack)
    n = len(needle)
    if n > m:
        return -1

    for i in range(m):
        start = -1
        end = -1
        if haystack[i] == needle[0]:
            start = i
            contains = False
            for j in range(n):
                if i+j > m-1:
                    break
                elif needle[j] != haystack[i+j]:
                    break
                elif j == n-1:
                    start = i
                    contains = True

            if contains:
                return start
    return -1


haystack = "mississippi"
needle = "issipi"
index = strstr(haystack, needle)
print("index: " + str(index))



haystack = "aaa"
needle = "aaaa"
#Output: 0
#Explanation: "sad" occurs at index 0 and 6.
index = strstr(haystack, needle)
print("index: " + str(index))




haystack = "sadbutsad"
needle = "sad"
#Output: 0
#Explanation: "sad" occurs at index 0 and 6.
index = strstr(haystack, needle)
print("index: " + str(index))

haystack = "leetcode"
needle = "leeto"
#Output: -1
#Explanation: "leeto" did not occur in "leetcode", so we return -1.
index = strstr(haystack, needle)
print("index: " + str(index))
