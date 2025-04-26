'''
https://leetcode.com/problems/next-permutation/

Intuition   1 3 5 2
 => from right, you need to get the first descending number 3 in 
        that is where you can possibly make a change.

    if i == -1, => everything is in the ascending order, the next sequence would be to reverse the digits.

    2) find smallest digit to the right that is greater than the pivot
        move from right => left
                    in above e.g its 5    
    3) swap nums[i] and nums[j]     1   5   3   2   => numbe becomes larger
    4) reverse after i =>   1   5   2   3   => reversing makes sure that we are getting the smallest number
////////////////////////////////////////////////////////
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
    
        



        
