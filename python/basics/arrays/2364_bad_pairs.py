'''
https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09


the idea is diff of (pos - value) will be same for good pairs.
as we iterate, we store this diff in hash map.

for every position, this position will form a pair with every count in the hash map..
    lets say the hash map has count 4:12, 12 positions with diff = 4.
    now, our ith position has the same diff = 4.
        So this ith position will form 12 good pairs.
            bad pairs = position num (total pairs) - good pairs.

            Add the bad pairs for all the positions
'''

def bad_pairs(nums: list[int]) -> int:
    N = len(nums)
    diff_counts = {}
    bad_pairs = 0
    for i in range(N):
        diff = i - nums[i]
        good_pairs_counts = 0
        if diff in diff_counts:
            good_pairs_counts = diff_counts[diff] 

        bad_pairs += i - good_pairs_counts
        if diff in diff_counts:
            diff_counts[diff] += 1
        else:
            diff_counts[diff] = 1
    return bad_pairs


nums = [4,1,3,3]
result = bad_pairs(nums)
print("result: " + str(result))
#Output: 5
#Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
#The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
#The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
#The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
#The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
#There are a total of 5 bad pairs, so we return 5.


nums = [1,2,3,4,5]
Output: 0
#Explanation: There are no bad pairs.
result = bad_pairs(nums)
print("result: " + str(result))
