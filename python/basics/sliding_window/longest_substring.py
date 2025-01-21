def longest_substring(input : str) -> int:
    l=0
    r=0
    startIndex=l
    endIndex=l
    maxLength = 0
    length = len(input)
    words = set()

    while l < length and r < length:
        startIndex = l
        while r < length:
            if input[r] not in words:
                words.add(input[r])
                print("added words: " + str(words))
                endIndex = r
                str_len = r - l + 1
                maxLength = max(maxLength, str_len)

                r += 1
                print("r-value: " + str(r))
            else:
                print("present: " + input[r] + " r:" + str(r) + " l:" + str(l))
                #if input[l] in words:
                print("before remove words: " + str(words))
                words.remove(input[l])
                    
                print("remove words: " + str(words))
                l += 1
    return maxLength

input = "abcabcbb"
length = longest_substring(input)
print("longest substring: " + str(length))