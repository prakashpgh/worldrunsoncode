'''
https://leetcode.com/problems/find-the-highest-altitude/

straight forward problem
'''

def highest_altitude(gain: list[int]) -> int:
    max_altitude = 0
    altitude = 0
    for g in gain:
        altitude += g
        max_altitude = max(altitude, max_altitude)
    return max_altitude


