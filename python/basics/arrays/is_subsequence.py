
def is_subsequence(a:str, b:str):
    j = 0
    n = len(b)
    if n == 0 :
        return True
    if n > len(T):
        return False
    
    for i in a:
        if i == b[j]:
            j += 1
        if j == n:
            return True
    return False

T = "abcdef"
S = "acf"
result = is_subsequence(T, S)
print("is_subsequence: " + str(result))

S = "acp"
result = is_subsequence(T, S)
print("is_subsequence: " + str(result))

T = "abcdeg"
S = "acf"
result = is_subsequence(T, S)
print("is_subsequence: " + str(result))

T = "abcdef"
S = ""
result = is_subsequence(T, S)
print("is_subsequence: " + str(result))

