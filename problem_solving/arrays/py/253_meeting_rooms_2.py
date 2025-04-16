'''
https://leetcode.com/problems/meeting-rooms-ii/
time: N log N
space: N
'''

def min_meeting_rooms(intervals: list[list[int]]) -> int:
    events = []
    for interval in intervals:
        events.append((interval[0], 1))
        events.append((interval[1], 0))
    events.sort(key=lambda x:(x[0], x[1]))

    current_rooms = 0
    max_rooms = 0
    for event in events:
        if event[1] == 1:
            current_rooms += 1
            max_rooms = max(max_rooms, current_rooms)
        else:
            current_rooms -= 1
    return max_rooms
                



intervals = [[0,30],[5,10],[15,20]]
#Output: 2
result = min_meeting_rooms(intervals)
print("result: " + str(result) )


intervals = [[7,10],[2,4]]
#Output: 1
result = min_meeting_rooms(intervals)
print("result: " + str(result) )


intervals = [[9,10],[4,9],[4,17]]
#Output: 2
result = min_meeting_rooms(intervals)
print("result: " + str(result) )
