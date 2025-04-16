
def reverse_string(input:list[str]):
    l = 0
    r = len(input)-1
    while l < r:
        tmp = input[l]
        input[l] = input[r]
        input[r] = tmp
        l += 1
        r -= 1
    return





s = ["h","e","l","l","o"]
reverse_string(s)
print("s: " + str(s))
#put: ["o","l","l","e","h"]


s = ["H","a","n","n","a","h"]
reverse_string(s)
print("s: " + str(s))
#Output: ["h","a","n","n","a","H"]


s = ["H","a"]
reverse_string(s)
print("s: " + str(s))
