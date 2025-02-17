#https://leetcode.com/problems/longest-increasing-subsequence/description/
#https://www.youtube.com/watch?v=DG50PJIx2SM

#https://www.youtube.com/watch?v=MrPa5EFcDCU&list=PLKYEe2WisBTFEr6laH5bR2J19j7sl5O8R&index=118
'''

https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
here iterative is the best solution
    iterate 1..N
        iterate 1..N
        O(n**2)        

        nlogn using binary search => https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
'''

def longest_increasing_subsequence(nums: list[int]):
    result = 0
    memo = [[-999]*3000 for i in range(3000)]
    #print ("memo: " + str(memo))

    def dp(current, prev):
        print("current: " + str(current) + " prev: " + str(prev))
        #base condition...
        if current >= len(nums):
            return 0
        if prev != -1 and memo[current][prev] != -999:
            return memo[current][prev]

        #skip
        ret1 = dp(current + 1, prev)
        ret2 = -1
        #take/include that character
        #if no previous element or if the prev is smaller..(increasing subsequence)
        if prev == -1 or nums[current] > nums[prev]:
            ret2 = 1 + dp(current + 1, current)

        memo[current][prev]=max(ret1, ret2)
        return memo[current][prev]

    #beginning index
    return dp(0, -1)

'''
store the lengths of lis in an array..
time: O(n2)
space: O(n)
'''
def longest_increasing_subsequence_iterative(nums: list[int]):
    N=len(nums)
    ans = [1] * N
    for i in range(1,N):
        max_is = 1
        for j in range(i):
            if nums[i] > nums[j]:
                max_is = max(max_is, ans[j]+1)
        ans[i] = max_is
    return max(ans)        



nums = [10,9,2,5,3,7,101,18]
result = longest_increasing_subsequence_iterative(nums)
#Output: 4
print("o: " + str(result))



nums = [0,1,0,3,2,3]
#Output: 4
result = longest_increasing_subsequence_iterative(nums)
print("o: " + str(result))

nums = [7,7,7,7,7,7,7]
#Output: 1
result = longest_increasing_subsequence_iterative(nums)
print("o: " + str(result))
