#https://www.youtube.com/watch?v=4Urd0a0BNng
#https://leetcode.com/problems/longest-common-subsequence/description/
#https://www.youtube.com/watch?v=DG50PJIx2SM
'''
Approach I : recursive
axyz baz, z matching
        axy ba, => we reduce the len of one of the strings.. and take max of 2


    1) base case: when m or n = 0, return 0

    2) start from the end...   last characters match..  do it with remaining

    3) last characters dont match... 
            max of the 2 options

Approach II:
    recursive with memo,just introduce memo

Approach III: bottom up
    uses logic similar to recursive
'''
def longest_common_subsequence(a:str, b:str, i:int, j:int)->int:
    #when length of the strings = 0, return 0
    if i == 0 or j == 0:
        return 0

    #axyz baz,  => z matching .. last character matches... increment count by 1, repeat for the remaining characters
    if a[i-1] == b[j-1]:
        return 1 + longest_common_subsequence(a, b, i-1,j-1)
    
    #axy ba, => we reduce the len of one of the strings.. and take max of 2 approaches
    return max( longest_common_subsequence(a, b, i, j-1), longest_common_subsequence(a, b, i-1, j))



def longest_common_subsequence_memo(a:str, b:str)->int:
    memo = {}
    def len_sequence(i, j):
        if (i, j) in memo:
            return memo[(i, j)]
        #when length of the strings = 0, return 0
        if i == 0 or j == 0:
            return 0

        #axyz baz,  => z matching .. last character matches... increment count by 1, repeat for the remaining characters
        if a[i-1] == b[j-1]:
            memo[(i,j)] = 1 + len_sequence(i-1,j-1)
            return memo[(i,j)]
        
        #axy ba, => we reduce the len of one of the strings.. and take max of 2 approaches
        memo[(i,j)] = max( len_sequence(i, j-1), len_sequence(i-1, j))
        return memo[(i,j)]
    return len_sequence(len(a), len(b))

#O(mn)
def longest_common_subsequence_bottom_up(a:str, b:str)->int:
    #m+1 for values from 0..M
    m = len(a)
    n = len(b)
    dp = [[None]* (n+1) for i in range(m+1)]
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif a[i-1] == b[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[m][n]


text1 = "abcde"
text2 = "ace" 
#Output: 3  
result = longest_common_subsequence(text1, text2, 5, 3)
print("result: " + str(result))

result = longest_common_subsequence_memo(text1, text2, 5, 3)
print("result-memo: " + str(result))

result = longest_common_subsequence_bottom_up(text1, text2)
print("result-bottomup: " + str(result))


text1 = "abc"
text2 = "abc"
#Output: 3
result = longest_common_subsequence(text1, text2, 3, 3)
print("result: " + str(result))

result = longest_common_subsequence_memo(text1, text2, 3, 3)
print("result-memo: " + str(result))

result = longest_common_subsequence_bottom_up(text1, text2)
print("result-bottomup: " + str(result))


text1 = "abc"
text2 = "def"
#Output: 0
result = longest_common_subsequence(text1, text2, 3, 3)
print("result: " + str(result))

result = longest_common_subsequence_memo(text1, text2, 3, 3)
print("result-memo: " + str(result))

result = longest_common_subsequence_bottom_up(text1, text2)
print("result-bottomup: " + str(result))
