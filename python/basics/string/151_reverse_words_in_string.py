#https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

def reverse_words_in_string(s):
    return " ".join(reversed(s.split()))

def reverse_words_in_string_code(s):
    N = len(s)
    r = 0
    for i in range(N-1, -1, -1):
        if s[i] != " ": #this line was wrong.
            r = i
            break
    start = -1
    end = r
    stk = []
    for i in range(r, -1, -1):
        if s[i] == " ":
            start = i+1
            word = s[start:end+1]
            stk.append(word)
            end = i - 1
            start = -1
    stk.append(s[0:end+1])  #mistake  - this line was missed

    return " ".join(stk)





s = "the sky is blue"
result = reverse_words_in_string(s)
#Output: "blue is sky the"
print("reversed: " + result)

result = reverse_words_in_string_code(s)
print("reversed: " + result)


s = "  hello world  "
#Output: "world hello"
#Explanation: Your reversed string should not contain leading or trailing spaces.


s = "a good   example"
#Output: "example good a"
#Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.