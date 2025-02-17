'''
https://leetcode.com/problems/edit-distance/

https://www.geeksforgeeks.org/edit-distance-dp-5/
Approach I: recursive
    start from end.. base case one of the string ends.

    if character match...  try with the strings with each index reduced by 1
    if character dont match, insert, replace, delete

    memoization: parameters m, n -lengths of the strings

Approach II:

'''


def edit_distance_recursive(word1:str, word2:str) -> int:
    l1=len(word1)
    l2=len(word2)
    
    def dp(word1, m, word2, n):
        if m == 0:
            return n
        if n == 0:
            return m
        
        if word1[m-1] == word2[n-1]:
            return dp(word1, m-1, word2, n-1)
        
        return 1 + min(dp(word1, m-1, word2, n-1),
                   dp(word1, m, word2, n-1),
                   dp(word1, m-1, word2, n))
    return dp(word1, l1, word2, l2)


#todo.. need to add memo
def edit_distance_recursive_memo(word1:str, word2:str) -> int:
    l1=len(word1)
    l2=len(word2)
    memo = [[0]*(l2+1) for i in range(l1+1)]
    def dp(word1, m, word2, n):
        if memo[m][n] != 0:
            return memo[m][n]
        
        if m == 0:
            memo[m][n] = n
            return n
        if n == 0:
            memo[m][n] = m
            return m
        
        if word1[m-1] == word2[n-1]:
            memo[m][n] = dp(word1, m-1, word2, n-1)
            return memo[m][n]
        
        memo[m][n] = 1 + min(dp(word1, m-1, word2, n-1),
                   dp(word1, m, word2, n-1),
                   dp(word1, m-1, word2, n))
        return memo[m][n]
    return dp(word1, l1, word2, l2)

#todo
def edit_distance_iterative(word1:str, word2:str) -> int:
    return -1


word1 = "horse"
word2 = "ros"
#Output: 3
#horse -> rorse (replace 'h' with 'r')
#rorse -> rose (remove 'r')
#rose -> ros (remove 'e')
result = edit_distance_recursive(word1, word2)
print("result-recur: " + str(result))

result = edit_distance_recursive_memo(word1, word2)
print("result-recur-memo: " + str(result))


word1 = "intention"
word2 = "execution"
#Output: 5

#intention -> inention (remove 't')
#inention -> enention (replace 'i' with 'e')
#enention -> exention (replace 'n' with 'x')
#exention -> exection (replace 'n' with 'c')
#exection -> execution (insert 'u')
result = edit_distance_recursive(word1, word2)
print("result-recur: " + str(result))

result = edit_distance_recursive_memo(word1, word2)
print("result-recur-memo: " + str(result))
