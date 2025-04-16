'''
https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150

sort on start-key
create this interval... and if next start lies in this interval... then adjust the end-point of the interval
'''

#O(n * logn)  => for sorting
def merge_intervals(nums:list[list[int]])->list[list[int]]:
    if not nums:
        return []
    nums.sort(key=lambda t:t[0])
    result = [nums[0]]
    j = 0
    for i in range(1, len(nums)):
        if nums[i][0] >= result[j][0] and nums[i][0] <= result[j][1]:
            result[j] = [min(result[j][0], nums[i][0]), max(result[j][1], nums[i][1])]
        else:
            result.append(nums[i])
            j += 1
    return result


nums = [[1,3],[2,6],[15,18],[8,10]]
result = merge_intervals(nums)
print("result:" + str(result))


nums = [[2,6],[1,3],[8,10],[7,9]]
result = merge_intervals(nums)
print("result:" + str(result))