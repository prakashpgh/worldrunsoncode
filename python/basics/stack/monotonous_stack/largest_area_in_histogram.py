'''
https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-using-stack/
'''


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
'''
def max_area_using_stack(nums: list[int]):
    n = len(nums)
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
    for i in range(n-1,0,-1):
        while stk and (nums[i] < stk[len(stk)-1][0]):
            (num, index) = stk.pop()
            result_pre[index] = i
        stk.append((nums[i], i))
    print("result_pre :" + str(result_pre))
    area = [0]*n
    for i in range(n):
        post = result_post[i]
        if post == -1:
            post = n-1+1
        pre = result_pre[i]
        if pre == -1:
            pre = 0

        area[i] = (post - pre -1) * nums[i]
    print("area: " + str(area))
    return max(area)


hist = [60, 20, 50, 40, 10, 50, 60]
area = max_area(hist)
print("area-1: " + str(area))

area = max_area_using_stack(hist)
print("area-2: " + str(area))


hist = [3, 5, 1, 7, 5, 9]
area = max_area(hist)
print("area: " + str(area))
