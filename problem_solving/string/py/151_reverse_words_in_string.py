'''
#https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150
traverse the string from 
'''


def reverse_words_in_string(s):
    return " ".join(reversed(s.split()))

from collections import deque

#right to left
def reverse_words_in_string_code__from_right(s):
    N = len(s)
    left = 0
    right = len(s) - 1
    q = deque()

    # remove leading spaces
    while left <= right and s[left] == " ":
        left += 1

    # remove trailing spaces
    while left <= right and s[right] == " ":
        right -= 1    

    while right >= left:
        word = []
        while left <= right:
            if s[left] != " ":
                word.append(s[left])
            elif s[left] == " " and word:
                q.appendleft("".join(word))
                word = []
            left += 1
        q.appendleft("".join(word))
    
    return " ".join(q)


#left to right
def reverse_words_in_string_code_from_left(s):
    N = len(s)
    left = 0
    right = len(s) - 1
    stk = []

    while right >= left:
        # remove leading spaces
        while left <= right and s[left] == " ":
            left += 1

        # remove trailing spaces
        while left <= right and s[right] == " ":
            right -= 1    

        word_start = left
        while left <= right and s[left] != " ":
            left += 1
        word = s[word_start:left]
        stk.append(word)
    stk.reverse()
    return " ".join(stk)



s = "a good   example"
result = reverse_words_in_string_code_from_left(s)
print("reverse_words_in_string_code: " + result)

result = reverse_words_in_string_code__from_right(s)
print("reverse_words_in_string_code__from_right: " + result)



s = "the sky is   blue"
result = reverse_words_in_string(s)
#Output: "blue is sky the"
print("reversed: " + result)

result = reverse_words_in_string_code__from_right(s)
print("reverse_words_in_string_code__from_right: " + result)




result = reverse_words_in_string_code_from_left(s)
print("reverse_words_in_string_code: " + result)

result = reverse_words_in_string_code__from_right(s)
print("reverse_words_in_string_code__from_right: " + result)


s = "  hello world  "
#Output: "world hello"
#Explanation: Your reversed string should not contain leading or trailing spaces.
result = reverse_words_in_string_code__from_right(s)
print("reverse_words_in_string_code__from_right: " + result)



#Output: "example good a"
#Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.