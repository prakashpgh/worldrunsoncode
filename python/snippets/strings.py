#frequency counters
s = "anagram"
f = [0]*26
for c in s:
    f[ord(c) - ord('a')] += 1

print(f)

###########
#isalnum()
s = "hello, world"
for c in s:
    if not c.isalnum():
        print(f"{c} is not alnum" )
