

def valid_anagram(s, t):
    s_set = set()
    t_set = set()
    for char in s:
        s_set.add(char)
    for char in t:
        t_set.add(char)
    return s_set == t_set


s = "anagram"
t = "nagaram"
result = valid_anagram(s, t)
print("result: " + str(result))

s = "rat"
t = "car"
result = valid_anagram(s, t)
print("result: " + str(result))