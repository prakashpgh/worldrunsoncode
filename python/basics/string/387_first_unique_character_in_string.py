'''
https://leetcode.com/problems/first-unique-character-in-a-string/

iterate the string, store the starting index and the frequency in dictionary.
iterate the dictionary, store the ones with only 1 occurence in a heap...  with key being the index
pop from heap

#meta


'''

def first_unique_character_in_string(input: str) -> int:
    pass





s = "leetcode"
#Output: 0


s = "loveleetcode"
#Output: 2



s = "aabb"
#Output: -1