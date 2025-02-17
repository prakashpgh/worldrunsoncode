'''
https://leetcode.com/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-interview-150

sort on start-key
create this interval... and if next start lies in this interval... then adjust the end-point of the interval
'''

#O(n * logn)  => for sorting
def merge_intervals(nums:list[list[int]])->list[list[int]]:
    result =[]
    n = len(nums)
    #sort
    nums.sort(key=lambda t:t[0])  #mistake i thought sort by end point
    print(str(nums))

    result.append(nums[0])
    j = 0
    #if the first of the interval lies in between the previous interval boundaries, merge.
    for i in range(n-1):
        if nums[i+1][0] > result[j][0] and nums[i+1][0] < result[j][1]:
            result[j][1]=max(nums[i+1][1], result[j][1])
        else:
            result.append(nums[i+1])
            j += 1
    
    return result


nums = [[1,3],[2,6],[15,18],[8,10]]
result = merge_intervals(nums)
print("result:" + str(result))


nums = [[2,6],[1,3],[8,10],[7,9]]
result = merge_intervals(nums)
print("result:" + str(result))