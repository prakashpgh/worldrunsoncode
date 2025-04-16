'''
https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150

t: O(n)
s: O(1)
#check
iterate ..
    for each element... find the other 2 elements.
    take care of duplicates ..by comparing i+1 and i
'''
def three_sum(nums):
    result = []
    nums.sort() #sorted
    N=len(nums)
    for i in range(N):
        if nums[i] > 0: #we can do this because the array is sorted
            break
        if i > 0 and nums[i] == nums[i-1]:
            continue
        l = i+1
        r = N-1
        while l < r:
            print(str(nums[i]) + " ~ " + str(nums[l]) + " ~ " + str(nums[r]))
            #print(str(nums[i]) + " ~ " + str(nums[l]) + " ~ " + str(nums[r]))
            sum = nums[i]+nums[l]+nums[r]
            if sum == 0:
                result.append([nums[i],nums[l],nums[r]])
                l += 1
                r -= 1
                while r > l and nums[r] == nums[r+1]:
                    r -= 1
                while r > l and nums[l] == nums[l-1]:
                    l += 1
            elif sum < 0:
                l += 1
            elif sum > 0:
                r -= 1

    return result

nums = [-1,0,1,2,-1,-4]
result = three_sum(nums)
print("result: " + str(result))
#Output: [[-1,-1,2],[-1,0,1]]

nums = [0,1,1]
result = three_sum(nums)
print("result: " + str(result))
#Output: []

nums = [0,0,0]
result = three_sum(nums)
print("result: " + str(result))
#Output: [[0,0,0]]

nums = [-2,0,0,2,2]
result = three_sum(nums)
print("result: " + str(result))

