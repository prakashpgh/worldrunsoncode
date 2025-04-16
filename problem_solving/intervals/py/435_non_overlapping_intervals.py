'''
https://leetcode.com/problems/non-overlapping-intervals/
'''

def erase_overlapping_intervals(intervals: list[list[int]]) -> int:
    intervals.sort(key=lambda x:x[1])
    end_time = float('-inf')
    ans = 0
    for i in range(len(intervals)):
        if intervals[i][0] < end_time:
            ans += 1
        else:
            end_time = intervals[i][1]
    return ans
        

intervals = [[1,2],[2,3],[3,4],[1,3]]
#Output: 1
result = erase_overlapping_intervals(intervals)
print("result = " + str(result))


intervals = [[1,2],[1,2],[1,2]]
#Output: 2
result = erase_overlapping_intervals(intervals)
print("result = " + str(result))


intervals = [[1,2],[2,3]]
#Output: 0
result = erase_overlapping_intervals(intervals)
print("result = " + str(result))
