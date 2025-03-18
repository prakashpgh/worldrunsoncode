#frequency counters
s = "anagram"
f = [0]*26
for c in s:
    f[ord(c) - ord('a')] += 1

print(f)

###########

