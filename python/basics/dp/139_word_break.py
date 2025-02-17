'''
https://leetcode.com/problems/word-break/
https://www.geeksforgeeks.org/word-break-problem-dp-32/

Idea is take the prefix of the word - one character at a given time
    check if its in the words list
'''

def word_break_recursive(s:str, word_dict:list[str]) -> bool:
    #print("s: " + s + " len:" + str(len(s)))
    if not s:
        return True
    
    word_len = len(s)

    for i in range(word_len+1): #mistake +1 was missing
        prefix = s[:i]
        #print("prefix: " + prefix)

        if prefix in word_dict:
            if word_break_recursive(s[i:], word_dict):
                return True
    return False


'''
    dp[len(s)] is empty string .. its true => base case
    traverse the string from end 
        string from i to end... check if it matches any one in the word dict.
            if yes,break

        return dp[0]

    https://www.youtube.com/watch?v=Sx9NNgInc3A&t=2s
'''
def word_break_iterative(s: str, word_dict: list[str]) -> bool:
    dp = [False] * (len(s) + 1)
    dp[len(s)] = True #base case

    for i in range(len(s) - 1, -1, -1):
        for w in word_dict:
            if (i + len(w)) <= len(s) and s[i:i+len(w) ] == w:
                dp[i] = dp[i + len(w)]
            if dp[i]:
                break
    return dp[0]



s = "leetcode"
wordDict = ["leet","code"]
#Output: true
#Explanation: Return true because "leetcode" can be segmented as "leet code".
result = word_break_recursive(s, wordDict)
print("result: " + str(result))


s = "applepenapple"
wordDict = ["apple","pen"]
#Output: true

s = "catsandog"
wordDict = ["cats","dog","sand","and","cat"]
#Output: false