
'''
https://leetcode.com/problems/trapping-rain-water/description/
max height to left
max height to right
min of [the max heights to right and left] - height of itself.  = water in that block....  
sum it up
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
            total_water += water
    return total_water


height = [0,1,0,2,1,0,1,3,2,1,2,1]
result = trapping_rain_water(height)
print("result: " + str(result))
#Output: 6

height = [4,2,0,3,2,5]
result = trapping_rain_water(height)
print("result: " + str(result))
#Output: 9
 