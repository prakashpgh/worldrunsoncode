'''
https://leetcode.com/problems/determine-if-two-strings-are-close/
1657_determine_strings_are_close.py

1) the distinct characters in the 2 words should be same
2) the freqency should be same, but the characters can be different

'''


def determine_strings_are_close(word1: str, word2: str) -> bool:
    freq1 = [0] * 26
    freq2 = [0] * 26

    for s in word1:
        freq1[ord(s) - ord('a')] += 1
    for s in word2:
        freq2[ord(s) - ord('a')] += 1

    #check if same distict characters are present
    for i in range(26):
        if (freq1[i] == 0 and freq2[i] > 0) or (freq2[i] == 0 and freq1[i] > 0):
            return False
    #check if frequencies are the same.
    freq2.sort()
    freq1.sort()
    if freq1 == freq2:
        return True
    return False



word1 = "abc"
word2 = "bca"
#Output: true
result = determine_strings_are_close(word1, word2)
print("result=" + str(result))

word1 = "a"
word2 = "aa"
#Output: false
result = determine_strings_are_close(word1, word2)
print("result=" + str(result))


word1 = "cabbba"
word2 = "abbccc"
#Output: true
result = determine_strings_are_close(word1, word2)
print("result=" + str(result))


