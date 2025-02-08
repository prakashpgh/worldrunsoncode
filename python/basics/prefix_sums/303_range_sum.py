'''
#https://leetcode.com/problems/range-sum-query-immutable/description/
'''

class NumArray:
    def __init__(self, nums: list[int]):
        self.nums = nums
        N=len(self.nums)
        for i in range(1,N):
            nums[i]=nums[i-1]+nums[i]
        print("nums: " + str(nums))

    def sum_range(self, left: int, right: int) -> int:
        if left==0:
            return self.nums[right]
        return self.nums[right] - self.nums[left-1]
        #return prefix[right] - prefix[left] + nums[i]


nums = [-2, 0, 3, -5, 2, -1]
num_array = NumArray(nums)
result = num_array.sum_range(0,2)
print("result: " + str(result))

result = num_array.sum_range(2,5)
print("result: " + str(result))

result = num_array.sum_range(0,5)
print("result: " + str(result))


#["NumArray", "sumRange", "sumRange", "sumRange"]
#[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
#[null, 1, -1, -3]
