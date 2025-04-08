'''
https://leetcode.com/problems/next-permutation/

321
1) from right, find the first descending element i
2) if i >= 0, find the smallest larger than [i]. .. this is j
3) swap [i] and [j]
4) reverse after i
'''


def next_permutation(nums: list[int]):
    N=len(nums)
    i = N-2
    # Step 1: Find the pivot (first decreasing element from right).. why decreasing.. because thats where you can change something to get the next larger number
    # e.g 3,2,1 .. you cannot change anything to get the next large number
    while i >= 0 and nums[i] >= nums[i+1]:
        i -= 1
    
    if i >= 0:
        j = N-1
        # Step 1: Find the pivot (first decreasing element from right)
        while j >= 0 and nums[j] <= nums[i]:
            j -= 1
        
        #swap
        nums[i], nums[j] = nums[j], nums[i]

    #reverse
    l = i + 1
    r = N - 1
    while l < r:
        nums[l], nums[r] = nums[r], nums[l]
        l += 1
        r -= 1
    
        



        
