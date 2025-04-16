#https://leetcode.com/problems/permutation-in-string/description/
#we want to check if the permutation of the s1 exists in s2
'''
    idea is in the s2, we find the counts..
    sliding windows = len of s1
'''
def permutation_in_string(s1, s2):
    result = False
    #find the s1 counts..
    N1 = len(s1)
    N2 = len(s2)
    if N2 < N1:
        return False
    
    a1 = [0]*26
    a2 = [0]*26

    for i in range(N1):
        a1[ord(s1[i])-ord('a')] += 1   #count for s1
        a2[ord(s2[i])-ord('a')] += 1    #count for s2 for the N1 characters

    if a1 == a2:
        return True

    #here we are just adding to the right of the window, and removing from the left of the window.. and compare with A1
    for i in range(N1, N2):
        a2[ord(s2[i])-ord('a')] += 1      #right of the window  
        a2[ord(s2[i-N1])-ord('a')] -= 1   #left of the window
        if a1 == a2:
            return True
        #compare a1 and a2

    return result


s1 = "ab"
s2 = "eidbaooo"
result = permutation_in_string(s1, s2)
print("result: " + str(result))
#Output: true
#Explanation: s2 contains one permutation of s1 ("ba").





s1 = "ab"
s2 = "eidboaoo"
#Output: false
result = permutation_in_string(s1, s2)
print("result: " + str(result))
