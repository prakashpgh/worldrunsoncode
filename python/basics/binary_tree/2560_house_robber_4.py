'''
https://leetcode.com/problems/house-robber-iv/

'''

def house_robber_4(nums: list[int], k:int) -> int:
    l = min(nums)
    r = max(nums)

    while l < r:
        m = l + (r-l)//2

        count = 0
        i = 0
        while i < len(nums):
            if nums[i] <= m:
                count += 1
                i += 2
            else:
                i += 1

        if count < k:
            l = m+1
        else:
            r = m
    return l



nums = [2,3,5,9]
k = 2
#Output: 5
result = house_robber_4(nums, k)
print("result=" + str(result))

nums = [2,7,9,3,1]
k = 2
#Output: 2
result = house_robber_4(nums, k)
print("result=" + str(result))
