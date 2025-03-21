'''
https://leetcode.com/problems/string-compression/

this seems easy problem.. but is quite tricky..
#interesting
'''

def string_compression(chars: list[str]) -> int:
    N = len(chars)
    w = 1
    if N==0:
        return 0
    group_char = chars[0]
    group_len = 0
    w = 0
    i = 0
    while i < N:
        if chars[i] != group_char:
            chars[w] = group_char
            w += 1
            if group_len > 1:
                for s in str(group_len):
                    chars[w] = s    
                    w += 1
            group_char = chars[i]
            group_len = 1
        else:
            group_len += 1
        i += 1

    if group_char:
    #print(chars)
        chars[w] = group_char
        w += 1
        if group_len > 1:
            for s in str(group_len):
                chars[w] = s    
                w += 1
    return w



chars = ["a","a","b","b","c","c","c"]
#Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
result = string_compression(chars)
print("result=" + str(result) + str(chars))



chars = ["a"]
#Output: Return 1, and the first character of the input array should be: ["a"]
result = string_compression(chars)
print("result=" + str(result) + str(chars))


chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
#Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
result = string_compression(chars)
print("result=" + str(result) + str(chars))
exit(0)
 