'''
https://leetcode.com/problems/spiral-matrix/description/?envType=study-plan-v2&envId=top-interview-150
#T O(n)
#S O(1)
'''

def spiral_matrix(nums: list[list[int]])->list[int]:
    result = []
    cols = len(nums[0])
    rows = len(nums)
    upper = 0
    lower = rows-1
    left = 0
    right = cols-1
    print("upper: {}  lower: {}  left: {}  right: {}".format(upper, lower, left, right))
    print("nums: " + str(nums))

    while len(result) < cols * rows:
        for i in range(left, right+1):
            result.append(nums[upper][i])
        upper += 1
        print("result 1: " + str(result))
        if(len(result) == cols * rows):
            break
        for j in range(upper, lower+1, 1):
            result.append(nums[j][right])
        right -= 1
        print("result 2: " + str(result))
        if(len(result) == cols * rows):
            break
        for k in range(right, left-1, -1):
            result.append(nums[lower][k])
        lower -= 1        
        print("result 3: " + str(result))
        if(len(result) == cols * rows):
            break
        for l in range(lower, upper-1, -1):
            result.append(nums[l][left])
        left += 1 
        print("result 4: " + str(result))
    return result



input = [[1,2,3],[4,5,6],[7,8,9]]
result = spiral_matrix(input)
print(str(result))


input = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
result = spiral_matrix(input)
print(str(result))
