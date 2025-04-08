'''
https://leetcode.com/problems/word-break-ii/

Approach: recursive approach.
    parameter: index of the string to start from..  start

    iterate the string from the start till the end..
        check if a word from dictionary is formed.
        if formed, recurse..
        append the results to form the string.

    exit criteria... start == len of the string.  return ""

    memoize
'''



def word_break_recursive_with_dp(s:str, word_dict:list[str]) -> str:
    dp = {}
    words = set(word_dict)
    N=len(s)

    def word_break_recursive_dp(start:int):
        if start in dp:
            return dp[start]
        
        results = []
        if start == N:
            results.append("")        
            return results
        
        for end in range(start+1, N+1): #mistake +1 was missing
            word = s[start:end]
            if word in word_dict:
                next_words = word_break_recursive_dp(end)
                for nw in next_words:
                    if nw == "":
                        results.append(word)
                    else:
                        results.append(word + " " + nw)
        dp[start] = results
        return results
    return word_break_recursive_dp(0)

s = "catsanddog"
wordDict = ["cats","dog","sand","and","cat"]
#Output: false
result = word_break_recursive_with_dp(s, wordDict)
print("result-dp: " + str(result))

