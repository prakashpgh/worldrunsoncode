#element which appears more than n/2 times
#Time O(n)
#space O(n)
def majority_element(nums:list[int])->int:
    n = len(nums)
    counter = {}
    max_occurence = 0
    max_num = nums[0]
    for num in nums:
        if num in counter:
            counter[num] += 1
        else:
            counter[num] = 1
        max_occurence = max(max_occurence, counter[num])
        max_num = num
    return max_num


input = [3,2,3]
result = majority_element(input)
print("result:" + str(result))
    

input = [2,2,1,1,1,2,2]
result = majority_element(input)
print("result:" + str(result))

input = [3,2,1,1,2,2,2,3,2]
result = majority_element(input)
print("result:" + str(result))
