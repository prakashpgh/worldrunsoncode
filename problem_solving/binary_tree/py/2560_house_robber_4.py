'''
https://leetcode.com/problems/house-robber-iv/

do binary search on the l=min and r=max. and find the capability as the mid-point
check if the capability works...
    basically avoid houses with value > this capabilty & check if you can rob K houses
'''

def house_robber_4(nums: list[int], k:int) -> int:
    l = min(nums)
    r = max(nums)

    def can_steal(capability):
        count = 0
        i = 0
        while i < len(nums):
            if nums[i] <= capability: #can steal house whose value <= capability
                count += 1
                i += 2
            else:
                i += 1
        return count >= k

    while l < r:
        m = l + (r-l)//2

        if can_steal(m):
            r = m
        else:
            l = m+1
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
