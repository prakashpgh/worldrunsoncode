#https://leetcode.com/problems/3sum-closest/
import sys

def three_sum_closest(nums: list[int], target) -> int:
    nums.sort()
    closest_sum = sys.maxsize
    for i in range(len(nums)-2):
        first = nums[i]
        l = i + 1
        r = len(nums)-1
        while r > l:
            sum = nums[l] + nums[r] + first
            if abs(target - sum) <= abs(target - closest_sum):
                closest_sum = sum
 
            if sum < target:
                l += 1
            elif sum > target:
                r -= 1
            else:
                return target
            
    return closest_sum



nums = [-1,2,1,-4]
target = 1
output = three_sum_closest(nums, target)
print("output: " + str(output))
#Output: 2



nums = [0,0,0]
target = 1
output = three_sum_closest(nums, target)
print("output: " + str(output))
#Output: 0

nums = [-3,-3,-2,0,1,2,2,3]
target=5
output = three_sum_closest(nums, target)
print("output: " + str(output))

#output: 5