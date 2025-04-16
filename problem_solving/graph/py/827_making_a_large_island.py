'''
https://leetcode.com/problems/making-a-large-island/description/

Idea: flipping from 0 to 1, figure out the adjacent islands touching this zero.  add up the areas of those islands..

Steps:
    1) create a dictionary of island id to area.  iterate the matrix, as soon as you find 1, explore the island, update the grid cells to unique ID starting from 2.
        find the are while exploring and store in dict.
    2) cases: a) if there is only 1 island, then you will increase the area by only 1.
            b) no islands, then 1{by this flip}
    3) now, iterate the grid again to find 0s, find the neighbors for this 0, {they should have the unique ids}, so you can find the unique islands surrounding 0.
        now addup the areas + 1(for the flip)
        do this for all zeros,and find the max.

#meta
'''


def making_a_large_island():
    pass