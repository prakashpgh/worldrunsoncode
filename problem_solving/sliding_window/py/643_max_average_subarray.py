'''
https://leetcode.com/problems/maximum-average-subarray-i/
'''

def max_average_subarray(nums: list[int], k: int) -> float : 
    N=len(nums)
    l = 0
    max_average = 0
    for i in range(k):
        max_average += nums[i]
    #print(max_average)    
    average = max_average
    for r in range(k, N):
        average += nums[r]
        average -= nums[l]
        l += 1
        #print("loop: " + str(average))
        max_average = max(max_average, average)
    return max_average/k


nums = [1,12,-5,-6,50,3]
k = 4
#Output: 12.75000
result = max_average_subarray(nums, k)
print("result= " + str(result))
