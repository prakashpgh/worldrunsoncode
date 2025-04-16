#element which appears more than n/2 times
#Time O(n)
#space O(n)
'''
use dictionary to find the frequency count.
check with freq. count > N//2
'''

def majority_element(nums:list[int])->int:
    n = len(nums)
    counter = {}
    max_num = nums[0]
    for num in nums:
        if num in counter:
            counter[num] += 1
        else:
            counter[num] = 1
        if counter[num] > n//2:
            max_num = num
            return num
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
