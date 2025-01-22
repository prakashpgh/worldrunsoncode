
def summary_ranges(nums:list[int])->list[str]:
    ranges = []
    if len(nums) == 0:
        return ranges
    start_index = 0
    end_index = -1
    n = len(nums)
    for i in range(1, n):
        if (nums[i] - nums[i-1] != 1):
            end_index = i-1
        if end_index != -1:
            if end_index != start_index:
                ranges.append(str(nums[start_index]) + "->" + str(nums[end_index]))
            else:
                ranges.append(str(nums[start_index]))
            start_index = i
            end_index = -1
    if end_index == -1:
        end_index = n-1
        if end_index != start_index:
            ranges.append(str(nums[start_index]) + "->" + str(nums[end_index]))
        else:
            ranges.append(str(nums[start_index]))

    return ranges




def summary_ranges_greg(nums:list[int])->list[str]:
    ranges = []

    i = 0
    n = len(nums)
    while i < n:
        start = nums[i]
        while i < n-1 and nums[i] + 1 == nums[i+1]:
            i += 1
        if start == nums[i]:
            ranges.append(str(start))            
        else:
            ranges.append(str(start) + "->" + str(nums[i]))            
        i += 1

    return ranges




nums=[0,1,2,4,5,7]
ranges = summary_ranges(nums)
print("ranges:" +str(ranges))

nums=[0]
ranges = summary_ranges(nums)
print("ranges:" +str(ranges))

nums=[0,2,3,4,6,8,9]
ranges = summary_ranges(nums)
print("ranges:" +str(ranges))

print("...GEG...")
nums=[0,1,2,4,5,7]
ranges = summary_ranges_greg(nums)
print("ranges:" +str(ranges))

nums=[0]
ranges = summary_ranges_greg(nums)
print("ranges:" +str(ranges))

nums=[0,2,3,4,6,8,9]
ranges = summary_ranges_greg(nums)
print("ranges:" +str(ranges))
