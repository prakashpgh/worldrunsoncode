'''
https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
'''
'''
Idea is to divide the whole into ranges.... each range is reached by a jump [min, max]
first range is the first stair case.
    Now you can jump to different stairs. 1..max_jump   
    these for the range.  the farthest is the max of this range... which is end variable.  
    so this range has [begin... end]
    
    from each of the stairs in that range, we find the farthest we can jump.
        when we tried the jump from end, that range is finished.  
            => Now we get the next range, and our jumpo count is updated, and the end of the next range is updated
'''
def jump_minimum_greedy(nums) -> bool:
    N=len(nums)
    jumps = 0
    farthest = 0
    end = 0
    for i in range(N-1):
        val = nums[i]
        farthest = max(farthest, i + val)

        if i == end:
            jumps += 1
            end = farthest
    return jumps
        



nums =  [1,1,2,5,2,1,0,0,1,3]
result = jump_minimum_greedy(nums)
print("result-recur: " + str(result))


nums =  [2,3,1,1,4]
result = jump_minimum_greedy(nums)
print("result-recur: " + str(result))
#2

nums = [2,3,0,1,4]
result = jump_minimum_greedy(nums)
print("result-recur: " + str(result))
#2