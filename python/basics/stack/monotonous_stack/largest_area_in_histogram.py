'''
https://leetcode.com/problems/largest-rectangle-in-histogram/
https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-using-stack/
'''

#time: O(n ** 2)
#space: O(1)
#iterate the array, 
#   for each bar, find the area with its height as the height of the histogram
#                   find the lower than itself to its left
#                   find the lower than itself to its right.
#                   you can get the area & max area
def max_area(nums) -> int:
    #print("max_area: " + str(nums) + " => " + str(type(nums)))
    max_area = 0
    n = len(nums)
    
    for i in range(n):
        area = nums[i]
        j = i -1
        while j >= 0 and nums[j] >= nums[i]:
            area += nums[i]
            j -= 1
        k = i + 1
        #print("nums type: " + str(type(nums)))
        while k < len(nums) and nums[k] >= nums[i]:
            area += nums[i]
            k += 1
        max_area = max(max_area, area)
        #print("max area: " + str(nums[i]) + "=>" + str(area) + "=>" + str(max_area))
    
    return max_area

'''
find the previous smaller using stacks
find the next smaller using stack
now you know the width...  and you can get the area for each.
find the max area
time: O(n)
space: O(n)
'''
def max_area_using_stack(nums: list[int]):
    n = len(nums)
    if n == 1:
        return nums[0]
    result_post = [-1]*n
    stk = []
    for i in range(n):
        while stk and (nums[i] < stk[len(stk)-1][0]):
            (num, index) = stk.pop()
            result_post[index] = i
        stk.append((nums[i], i))
    print("result_post:" + str(result_post))

    result_pre = [-1]*n
    stk = []
    for i in range(n-1,-1,-1):
        while stk and (nums[i] < stk[len(stk)-1][0]):
            (num, index) = stk.pop()
            result_pre[index] = i
        stk.append((nums[i], i))
    print("result_pre :" + str(result_pre))
    area = [0]*n
    for i in range(n):
        post = result_post[i]
        if post == -1:
            post = n
        pre = result_pre[i]
        if pre == -1:
            pre = -1

        area[i] = (post - pre -1) * nums[i]
    print("area: " + str(area))
    print("max-area: " + str(max(area)))
    return max(area)


hist = [1,1]
#area = max_area(hist)
#print("area-1: " + str(hist) + " = " + str(area))
area = max_area_using_stack(hist)
print("area-stack: " + str(hist) + " = " + str(area))

print("====================")
hist = [60, 20, 50, 40, 10, 50, 60]
#100
#area = max_area(hist)
#print("area-1: " + str(hist) + " = " + str(area))
area = max_area_using_stack(hist)
print("area-stack: " + str(hist) + " = " + str(area))

print("====================")
hist = [3, 5, 1, 7, 5, 9]
#area = max_area(hist)
#print("area-1: " + str(hist) + " = " + str(area))
area = max_area_using_stack(hist)
print("area-stack: " + str(hist) + " = " + str(area))

print("====================")
hist = [2,4]
#4
area = max_area_using_stack(hist)
print("area-stack: " + str(hist) + " = " + str(area))

print("====================")
hist = [2,1,5,6,2,3]
#10
area = max_area_using_stack(hist)
print("area-stack : " + str(hist) + " = " + str(area))
