'''
https://leetcode.com/problems/reverse-vowels-of-a-string/
'''

def reverse_vowels(s: str) -> str:
    vowels = set("aeiouAEIOU")
    s = list(s)
    N=len(s)
    l = 0
    r = len(s) -1
    print(s)
    while l < r:
        while l < r and s[l] not in vowels:
            l += 1
        while l < r and s[r] not in vowels:
            r -= 1
        print(l)
        print(r)
        if l < r and s[l] in vowels and s[r] in vowels:
            s[l],s[r] = s[r], s[l]
            l += 1
            r -= 1

    return "".join(s)



s = "IceCreAm"
#Output: "AceCreIm"
result = reverse_vowels(s)
print("result: " + result)

s = "leetcode"
#Output: "leotcede"
result = reverse_vowels(s)
print("result: " + result)
