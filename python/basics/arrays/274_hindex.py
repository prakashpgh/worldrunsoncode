'''
https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
approach i => brute force
'''

#hindex
#iterate the possible h-indexes 0-N, and try if it works.
#this can start from highest value.  len(nums) = max h-index
#time: O(n)
#space: O(1)
def hindex_bruteforce(nums):
    N = len(nums)
    h = 0
    for i in range(N):
        count = 0
        for j in range(N):
            if nums[j] >= i:
                count += 1
            if count >= i:
                h=i
                break
    return h

'''
create a hash of the counts.
go thru the possible hashes from max... check the values from the hash table
time O(n)
space O(n)
'''
def hindex(nums):
    N = len(nums)
    h = 0
    citations = [0]*(N+1)
    for i in range(N):
        index = nums[i]
        if index >= N:
            index = N
        citations[index] += 1
    print("citations: " + str(citations))
    sum_citations = 0
    for i in range(N,-1,-1):
        sum_citations += citations[i]
        if sum_citations >= i:
            return i

nums = [5,1,2,8,9,3]
h = hindex_bruteforce(nums)
print("h=" + str(h))

h = hindex(nums)
print("h=" + str(h))

