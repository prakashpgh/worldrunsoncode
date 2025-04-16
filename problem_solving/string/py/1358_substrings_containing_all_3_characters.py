'''
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

2-pointer..

iterate r in a loop
    whenever at least one of a, b,c are there
        l++
        reduce the frequency
        total += len(s) - r => when you in the while loop, thats the minimum requirement for the substring with all characters... so if we add from r... len(s)-1  those are the possible substrings
'''

def substrings_containing_all_3_characters():
