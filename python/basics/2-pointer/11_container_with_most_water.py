#https://leetcode.com/problems/container-with-most-water/description/

#2-pointer - move the pointer with lesser height
#time O(n)
#space O(1)
def container_with_most_water(height):
    result = 0
    #l h
    #min  & width

    N = len(height)
    l = 0
    r = N-1
    max_area = 0
    while r > l:
        min_height = min(height[l], height[r])
        area = min_height * (r-l)
        max_area = max(area, max_area)
        if height[l] >= height[r]:
            r -= 1
        elif height[l] < height[r]:
            l += 1
    return max_area




height = [1,8,6,2,5,4,8,3,7]
result = container_with_most_water(height)
print("result: " + str(result))
#Output: 49

#Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


height = [1,1]
result = container_with_most_water(height)
print("result: " + str(result))

#output 1
