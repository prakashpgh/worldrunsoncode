#jump game 1
#https://leetcode.com/problems/jump-game/description/


#traverse from end to begin..
#check if we can reach that point..
#revise that point till its the first point
# time: O(n)
def jump_game_yesno_greedy(nums:list[int]) -> bool:
    result = False
    N=len(nums)
    final = N-1
    for i in range(N-2, -1, -1):
        if (i + nums[i] >= final):
            final = i
    return final == 0




nums = [2,3,1,1,4]
#true
result = jump_game_yesno_greedy(nums)
print("result-greed: " + str(result))

#result = jump_game_yesno_recursive(nums)
#print("result-recur: " + str(result))

#false
nums = [3,2,1,0,4]
result = jump_game_yesno_greedy(nums)
print("result-greed: " + str(result))

#result = jump_game_yesno_recursive(nums)
#print("result-recur: " + str(result))
