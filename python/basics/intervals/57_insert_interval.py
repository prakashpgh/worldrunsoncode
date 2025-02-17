'''
https://leetcode.com/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150

https://www.youtube.com/watch?v=A8NUOmlwOlM
#interesting

iterate the original list linearly,
    3 cases
        1) the new_interval ends before the interval => add the new node.. add the rest
        2) the new_interval starts after the end of interval => add the interval
        3) the new interval overlaps with the interval, create the new_inteval : min of starts, max of ends
            dont add the new interval.  Add it in the end of the loop
'''


def insert_interval_linear(intervals: list[list[int]], new_interval:list[int]):
    result = []

    for i in range(len(intervals)):
        #new ends before next start - non overlapping
        if new_interval[1] < intervals[i][0]:
            result.append(new_interval)
            return result + intervals[i:]
        #non-overlapping - starts before the next one
        elif new_interval[0] > intervals[i][1]:#nonoverlapping
            result.append(intervals[i])
        else:
            new_interval = [min(new_interval[0], intervals[i][0]),
                            max(new_interval[1], intervals[i][1])]
    result.append(new_interval)
    return result

def insert_interval(intervals: list[list[int]], new_interval:list[int]):
    len_intervals = len(intervals)
    l = 0
    r = len_intervals-1
    result = intervals.copy()
    #binary search to find the insertion point
    index = -1
    while l <= r:
        m = l + (r-l)//2
        if new_interval[0] == intervals[m][0]:
            index = m
            break
        elif new_interval[0] > intervals[m][0]:
            l = m+1
        else:
            r = m-1
    if index == -1:
        index = r
    #print("index: " + str(intervals[index]) + str(intervals[l]) + str(intervals[m]) )

    #result = intervals.copy()
    #result.insert(l, new_interval)
    result = []

    for i in range(len(intervals)):
        if not result or (result[-1][1] < new_interval[0]):
            result.append(i)
        else:
            result[-1][1] = max(result[-1][1], new_interval[1])
    return result

intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
new_interval = [4,8]
#Output: [[1,2],[3,10],[12,16]]
#Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
print("intervals-before: " + str(intervals))
result = insert_interval_linear(intervals, new_interval)
print("intervals-after: " + str(result))


intervals = [[1,3],[6,9]]
new_interval = [2,5]
#Output: [[1,5],[6,9]]
#Example 2:
print("intervals-before: " + str(intervals))
result = insert_interval_linear(intervals, new_interval)
print("intervals-after: " + str(result))


