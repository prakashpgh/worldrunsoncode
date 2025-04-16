#time: O(n)
def max_average(nums: list[int], k):
    max_sum = 0
    l = 0
    r = l + k
    n = len(nums)
    
    for i in range(k):
        max_sum += nums[i]

    sum = max_sum
    for l in range(1, n-k+1):
        sum = sum - nums[l-1]+nums[l+k-1]
        max_sum = max(max_sum, sum)

    return max_sum/k


nums = [1,12,-5,-6,50,3]
k = 4
average = max_average(nums, k)
print("average:" + str(average))



