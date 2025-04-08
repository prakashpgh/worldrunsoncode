'''
https://leetcode.com/problems/word-break/
https://www.geeksforgeeks.org/word-break-problem-dp-32/

Approach I:
recursive.. traverse the string, for each letter, check any words match.
if they match, repeat with the index starting from next
    exit: the index == len of string
    You can add dp to this to optimize

Approach II:Iterative.


'''

def word_break_recursive(index:int, s:str, word_dict:list[str]) -> bool:
    if index == len(s):
        return True
    
    word_len = len(s)
    for i in range(index, word_len): #mistake +1 was missing
        if s[index:i+1] in word_dict and word_break_recursive(i+1, s, word_dict):
            return True
    return False


def word_break_recursive_dp(index:int, s:str, word_dict:list[str], dp) -> bool:
    if index == len(s):
        return True
    if index in dp:
        return dp[index]
    
    word_len = len(s)
    for i in range(index, word_len): #mistake +1 was missing
        if s[index:i+1] in word_dict and word_break_recursive(i+1, s, word_dict):
            dp[index] = True
            return True
    dp[index] = False
    return dp[index]


def word_break_recursive_with_dp(index:int, s:str, word_dict:list[str]) -> bool:
    dp = [-1] * (len(s)+1)
    return word_break_recursive_dp(0, s, word_dict, dp)


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
    dp[0] = True #base case
    N=len(s)

    for i in range(1, N+1):
        for w in word_dict:
            wl = len(w)
            start = i - wl
            if start >= 0 and start <= len(s) and dp[start] and s[start:start+wl] == w:
                dp[i] = True
                break
    return dp[N]==True



s = "leetcode"
wordDict = ["lee", "leet","code"]
#Output: true
#Explanation: Return true because "leetcode" can be segmented as "leet code".
result = word_break_recursive(0, s, wordDict)
print("result: " + str(result))

result = word_break_recursive_with_dp(0, s, wordDict)
print("result-dp: " + str(result))

result = word_break_iterative(s, wordDict)
print("result-iterative: " + str(result))



s = "applepenapple"
wordDict = ["apple","pen"]
#Output: true
result = word_break_recursive(0, s, wordDict)
print("result: " + str(result))

result = word_break_recursive_with_dp(0, s, wordDict)
print("result-dp: " + str(result))

result = word_break_iterative(s, wordDict)
print("result-iterative: " + str(result))


s = "catsandog"
wordDict = ["cats","dog","sand","and","cat"]
#Output: false
result = word_break_recursive(0, s, wordDict)
print("result: " + str(result))

result = word_break_recursive_with_dp(0, s, wordDict)
print("result-dp: " + str(result))

result = word_break_iterative(s, wordDict)
print("result-iterative: " + str(result))
