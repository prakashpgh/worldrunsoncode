
'''
https://leetcode.com/problems/trapping-rain-water/description/

Approach I:
max height to left
max height to right
min of [the max heights to right and left] - height of itself.  = water in that block....  
sum it up

Approach II:
    monotonous stack approach.

Approach III:
    2-pointer approach
    start pointers from both the ends..
    if l < r, move l, else move r => 
    keep tab of left_max and right_max
    if l > left_max, update left_max, no water can be stored here. same logic for r

'''
def trapping_rain_water(height):
    N = len(height)

    max_left = [0]*N
    left = 0
    for i in range(N):
        max_left[i]=left
        left = max(left, height[i])
    #print("left: " + str(max_left))
    right = 0
    max_right = [0]*N
    for i in range(N-1, -1, -1):
        max_right[i]=right
        right = max(right, height[i])
    #print("right: " + str(max_right))
    total_water = 0
    for i in range(N):
        possible = min(max_left[i], max_right[i])
        if height[i] < possible:
            water = possible - height[i]
            if water:
                total_water += water
    return total_water


def trapping_rain_water_2pointer(height):
    N = len(height)
    l = 0
    r = N-1
    l_max = 0
    r_max = 0
    water = 0
    while l < r:
        if height[l] < height[r]:
            if height[l] > l_max:
                l_max = height[l]
            else:
                water += l_max - height[l]
            l += 1
        else:
            if height[r] > r_max:
                r_max = height[r]
            else:
                water += r_max - height[r]
            r -= 1
    return water




height = [0,1,0,2,1,0,1,3,2,1,2,1]
result = trapping_rain_water(height)
print("result: " + str(result))


result = trapping_rain_water_2pointer(height)
print("result-2pointer: " + str(result))
#Output: 6

height = [4,2,0,3,2,5]
result = trapping_rain_water(height)
print("result: " + str(result))
#Output: 9
result = trapping_rain_water_2pointer(height)
print("result-2pointer: " + str(result))
 