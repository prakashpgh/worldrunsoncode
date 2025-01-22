
#O(n)
#O(n)

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


def longest_substring_2(input : str) -> int:
    n = len(input)
    l = 0
    r = 0
    words_set = set()
    max_word_length = 0
    for r in range(n):
        if input[r] not in words_set:
            words_set.add(input[r])
            word_length = r - l + 1
            max_word_length = max(max_word_length, word_length)
        else:
            print("words_set: " + str(words_set))
            while(input[r] in words_set):
                words_set.remove(input[l])
                l += 1
            words_set.add(input[r])
        
    return max_word_length


input = "abcabcbb"
#length = longest_substring(input)
#print("longest substring: " + str(length))

length = longest_substring_2(input)
print("longest substring 2: " + str(length))