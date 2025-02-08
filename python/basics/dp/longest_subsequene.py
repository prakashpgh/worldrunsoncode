#https://www.youtube.com/watch?v=4Urd0a0BNng
#https://leetcode.com/problems/longest-common-subsequence/description/
#https://www.youtube.com/watch?v=DG50PJIx2SM

'''
    base case.
    start from the end...
        last characters match..

        last characters dont match... 
            max of the 2 options
'''
def longest_common_subsequence(a:str, b:str, i:int, j:int)->int:
    if i == 0 or j == 0:
        return 0
    
    if a[i-1] == b[j-1]:
        return 1 + longest_common_subsequence(a, b, i-1,j-1)
    
    return max( longest_common_subsequence(a, b, i, j-1), longest_common_subsequence(a, b, i-1, j))




text1 = "abcde"
text2 = "ace" 
#Output: 3  
result = longest_common_subsequence(text1, text2, 5, 3)
print("result: " + str(result))


text1 = "abc"
text2 = "abc"
#Output: 3
result = longest_common_subsequence(text1, text2, 3, 3)
print("result: " + str(result))


text1 = "abc"
text2 = "def"
#Output: 0
result = longest_common_subsequence(text1, text2, 3, 3)
print("result: " + str(result))
