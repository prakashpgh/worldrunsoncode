#T: O(n**2)
#S: O(1)
#transpose + reflect along vertical
def rotate_image(nums: list[list[int]])->list[list[int]]:
    rows = len(nums)
    cols = len(nums[0])
    #transpose
    for i in range(rows):
        for j in range(i+1, cols):
            nums[j][i],nums[i][j]  = nums[i][j],nums[j][i]
            print("nums: " + str(nums))        

    #reflection
    for i in range(rows):
        for j in range(cols//2):
            nums[i][j], nums[i][cols-j-1]  = nums[i][cols-j-1], nums[i][j]
    return nums


input = [[1,2,3],[4,5,6],[7,8,9]]
print("input:" + str(input))
result = rotate_image(input)
print("result:" + str(result))


input = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
print("input:" + str(input))
result = rotate_image(input)
print("result:" + str(result))
