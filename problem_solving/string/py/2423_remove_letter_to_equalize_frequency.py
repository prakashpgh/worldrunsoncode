'''
https://leetcode.com/problems/remove-letter-to-equalize-frequency/
get all the frequencies in a list
iterate the list
    make a copy of the list.
    remove zeros..
    reduce count of ith
    remaining > 0
    all(x == remaining[0] for all x in remining )

'''

def remove_letter_to_equalize_frequency():
    return False