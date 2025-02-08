#https://leetcode.com/problems/4sum/description/

'''
iterate for the 1st..
    iterate for the 2nd
        use 2 pointer for 3rd and 4th
'''
def four_sum(nums: list[int], target):
    nums.sort()
    N = len(nums)
    output = []
    for i in range(N):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        for j in range(i+1, N):
            if j > i+1 and nums[j] == nums[j-1]:
                continue
            l = j + 1
            r = N-1
            while( r > l):
                sum = nums[i] + nums[j] + nums[l] + nums[r]
                if sum == target:    
                    output.append([nums[i],nums[j],nums[l],nums[r]])
                    l += 1
                    r -= 1
                    #to avoid duplicates
                    while(r > l and (nums[r] == nums[r+1])):
                        r -= 1
                    while(r > l and (nums[l] == nums[l-1])):
                        l += 1
                elif sum > target:
                    r -= 1
                    #to avoid duplicates
                    while(r > l and (nums[r] == nums[r+1])):
                        r -= 1
                else:
                    l += 1    
                    #to avoid duplicates
                    while(r > l and (nums[l] == nums[l-1])):
                        l += 1     
    return output





nums = [1,0,-1,0,-2,2]
target = 0
#Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
output = four_sum(nums, target)
print("output: " + str(output))



nums = [2,2,2,2,2]
target = 8
output = four_sum(nums, target)
print("output: " + str(output))

#Output: [[2,2,2,2]]

nums=[-2,-1,-1,1,1,2,2]
target=0
output = four_sum(nums, target)
print("output: " + str(output))

