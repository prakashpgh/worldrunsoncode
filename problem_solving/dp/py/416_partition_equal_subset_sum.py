'''

'''

def partition_equal_subset_sum(nums: list[int]) -> bool:
    total = sum(nums)
    if total % 2 != 0:
        return False
    target = total // 2
    memo = {}

    def can_partition(index, target):
        if (index, target) in memo:
            return memo[(index, target)]
        if target == 0:
            memo[(index,target)] = True
            return True
        if target < 0 or index >= len(nums):
            memo[(index,target)] = False
            return False

        result = can_partition(index+1, target) or can_partition(index+1, target-nums[index])
        memo[(index,target)] = result
        return result

    return can_partition(0, target)




nums = [1,5,11,5]
#Output: true
result = partition_equal_subset_sum(nums)
print("result=" + str(result))


nums = [1,2,3,5]
#Output: false
result = partition_equal_subset_sum(nums)
print("result=" + str(result))
