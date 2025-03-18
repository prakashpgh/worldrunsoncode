'''
https://leetcode.com/problems/meeting-rooms/description/

sort by start times
find overlaps... end time can be equal to start time
'''

def can_attend_meetings(intervals: list[list[int]]) -> bool:
    intervals.sort(key= lambda x:x[0])
    for i in range(1, len(intervals)):
        if intervals[i][0] >= intervals[i-1][0] and intervals[i][0] < intervals[i-1][1]:
            return False
    return True



intervals = [[0,30],[5,10],[15,20]]
#Output: false
result = can_attend_meetings(intervals)
print("result=" + str(result))


intervals = [[7,10],[2,4]]
#Output: false
result = can_attend_meetings(intervals)
print("result=" + str(result))