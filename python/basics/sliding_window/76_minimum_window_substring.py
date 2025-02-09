'''
https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150

put in hash map

iterate s... r pointer...
    l-pointer => move when 

##good problem
variable to track that the characters and their frequency are same..
'''
import sys
from collections import Counter

def minimum_window_substring(s: str, t: str) -> str:
        if not t or not s:
            return ""

        # Dictionary which keeps a count of all the unique characters in t.
        dict_t = Counter(t)

        # Number of unique characters in t, which need to be present in the desired window.
        required = len(dict_t)

        # left and right pointer
        l, r = 0, 0

        # formed is used to keep track of how many unique characters in t are present in the current window in its desired frequency.
        # e.g. if t is "AABC" then the window must have two A's, one B and one C. Thus formed would be = 3 when all these conditions are met.
        formed = 0

        # Dictionary which keeps a count of all the unique characters in the current window.
        window_counts = {}

        # ans tuple of the form (window length, left, right)
        ans = float("inf"), None, None

        while r < len(s):

            # Add one character from the right to the window
            character = s[r]
            if character in dict_t:
                window_counts[character] = window_counts.get(character, 0) + 1

            # If the frequency of the current character added equals to the desired count in t then increment the formed count by 1.
            if (
                character in dict_t
                and window_counts[character] == dict_t[character]
            ):
                formed += 1

            # Try and contract the window till the point where it ceases to be 'desirable'.
            while l <= r and formed == required:
                character = s[l]

                # Save the smallest window until now.
                if r - l + 1 < ans[0]:
                    ans = (r - l + 1, l, r)

                # The character at the position pointed by the `left` pointer is no longer a part of the window.
                if character in dict_t:
                    window_counts[character] -= 1
                if (
                    character in dict_t
                    and window_counts[character] < dict_t[character]
                ):
                    formed -= 1

                # Move the left pointer ahead, this would help to look for a new window.
                l += 1

            # Keep expanding the window once we are done contracting.
            r += 1
        return "" if ans[0] == float("inf") else s[ans[1] : ans[2] + 1]

def minimum_window_substring_2(s:str, t:str) -> str:
    hash = {}
    for ch in t:
        if ch not in hash:
            hash[ch] = 1
        else:
            hash[ch] += 1

    l = 0
    r = 0
    hash_copy = {}
    min_window_len = sys.maxsize
    min_r = 0
    min_l = 0
    required = len(hash)
    formed = 0
    N=len(s)
    for r in range(N):
        print("char is " + str(r) + " => " + s[r])
        character = s[r]
        if character in hash:
            hash_copy[character] = hash_copy.get(character, 0) + 1
        if character in hash and hash_copy[character] == hash[character]:
            formed += 1

        while l <= r and formed == required:
            print("char is l=" + str(l) + " => " + s[l])            
            character = s[l]
            if r - l + 1 < min_window_len:
                min_window_len = r-l+1
                min_l=l
                min_r=r

            if character in hash:
                hash_copy[character] -= 1
            if character in hash and hash_copy[character] < hash[character]:
                formed -= 1
            l += 1        
    print("l=" + str(l) + " r=" + str(r))
    return s[min_l:min_r+1]



s = "ADOBECODEBANC"
t = "ABC"
#Output: "BANC"
#Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
result = minimum_window_substring(s, t)
print("result: " + result)

result = minimum_window_substring_2(s, t)
print("result: " + result)


s = "a"
t = "a"
#Output: "a"
#Explanation: The entire string s is the minimum window.
#Example 3:

s = "a"
t = "aa"
#Output: ""
#Explanation: Both 'a's from t must be included in the window.
