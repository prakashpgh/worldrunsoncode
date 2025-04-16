'''
https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150

important thing is to strip the blanks at the end
'''


def length_of_last_word(s: str) -> int:
    N=len(s)
    word_len = 0
    r = N-1
    for i in range(N-1,-1,-1):  #mistake - forgot to strip the blanks
        if s[i] != " ":
            break
        r -= 1

    for i in range(r,-1,-1):
        if s[i] == " ":
            break
        word_len += 1
    return word_len






s = "Hello World"
#Output: 5
#Explanation: The last word is "World" with length 5.
l = length_of_last_word(s)
print("length_of_last_word: " + str(l))

s = "   fly me   to   the moon  "
#Output: 4
#Explanation: The last word is "moon" with length 4.
l = length_of_last_word(s)
print("length_of_last_word: " + str(l))


s = "luffy is still joyboy"
#Output: 6
#Explanation: The last word is "joyboy" with length 6.
l = length_of_last_word(s)
print("length_of_last_word: " + str(l))
